/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:29 by exenia            #+#    #+#             */
/*   Updated: 2021/04/12 23:41:22 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char			*cmd_parse(char *str, char ***cmds,
	long long int **fds, t_shell *shell)
{
	int		len;
	int		i;

	len = find_cmd_len(str);
	i = 0;
	if ((*cmds = (char**)malloc(sizeof(char *) * (len + 1))) == NULL)
		malloc_error_exit();
	(*cmds)[len] = NULL;
	while (*str && not_one_of_the_set(*str, "|;"))
	{
		while (*str && *str == ' ')
			str++;
		if (!(*str) || one_of_the_set(*str, "|;"))
			break ;
		if (*str && one_of_the_set(*str, "><"))
			str = redirection_parse(str, &(*fds), shell);
		else
			str = parse_by_space(str, &((*cmds)[i++]), shell);
	}
	(*cmds)[i] = NULL;
	if (!(*str) || *str == ';')
		return (str);
	else
		return (++str);
}

void			free_data(t_data *data)
{
	int i;
	int j;

	i = 0;
	if (data->size == 0)
		return ;
	while (data->cmds[i] != NULL)
	{
		j = 0;
		while (data->cmds[i][j])
			free(data->cmds[i][j++]);
		free(data->cmds[i][j]);
		free(data->cmds[i++]);
	}
	i = 0;
	while (i < data->size)
		free(data->fds[i++]);
	free(data->fds);
	free(data->cmds);
	free(data);
}

long long int	**init_fds(long long int **fds, t_shell *shell)
{
	if ((fds[shell->i] =
		(long long int*)malloc(sizeof(long long int) * 6)) == NULL)
		malloc_error_exit();
	fds[shell->i][0] = 0;
	fds[shell->i][1] = 1;
	fds[shell->i][2] = 2;
	fds[shell->i][3] = 0;
	fds[shell->i][4] = 0;
	fds[shell->i][5] = 0;
	return (fds);
}

t_data			*pre_parse_cmds(t_shell *shell, char **str)
{
	t_data			*data;
	int				len;
	char			***cmds;
	long long int	**fds;

	data = (t_data *)malloc(sizeof(t_data));
	shell->i = 0;
	len = find_cmds_count(*str) + 1;
	if ((cmds = (char ***)malloc(sizeof(char **) * len)) == NULL)
		malloc_error_exit();
	if ((fds = (long long int **)malloc(sizeof(long long int *) * len)) == NULL)
		malloc_error_exit();
	data->size = 0;
	while (**str && **str != ';')
	{
		init_fds(fds, shell);
		*str = cmd_parse(*str, &(cmds[shell->i]), &(fds[shell->i]), shell);
		data->cmds = cmds;
		data->fds = fds;
		shell->i++;
		data->size = shell->i;
	}
	cmds[shell->i] = NULL;
	return (data);
}

void			parse(char *str, t_shell *shell)
{
	t_data	*data;
	char	*tmp;

	str = get_new_line(str, &(shell->flags));
	tmp = str;
	shell->j = 0;
	while (*str)
	{
		data = pre_parse_cmds(shell, &str);
		ft_cmd_in_pipe(data, shell);
		free_data(data);
		str = check_token(str, shell);
	}
	free(tmp);
	if (shell->flags)
		free(shell->flags);
	shell->flags = NULL;
}
