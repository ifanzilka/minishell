/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_of_gang_parsers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:29 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 21:10:09 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *cmd_parse(char *str, char ***cmds, int **fds, t_shell *shell)
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
			break;
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

void	free_data(t_data *data)
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
		free(data->cmds[i++]);
	}
	free(data->cmds);
	i = 0;
	while (i < data->size)
		free(data->fds[i++]);
	free(data->fds);
}

void	parse(char *str, t_shell *shell)
{
	int		i;
	char	***cmds;
	t_data	data;
	int		len;
	int		**fds;

	//сделать зануление
	while (*str)
	{
		i = 0;
		len = find_cmds_count(str) + 1;
		if ((cmds = (char ***)malloc(sizeof(char **) * len)) == NULL)
			malloc_error_exit();
		if ((fds = (int **)malloc(sizeof(int *) * len)) == NULL)
			malloc_error_exit();
		data.size = 0;
		while (*str && *str != ';')
		{
				if ((fds[i] = (int*)malloc(sizeof(int) * 5)) == NULL)
					malloc_error_exit();
				fds[i][0] = 0;
				fds[i][1] = 1;
				fds[i][2] = 2;
				fds[i][3] = 0;
				fds[i][4] = 0;
				str = cmd_parse(str, &(cmds[i]), &(fds[i]), shell);
				data.cmds = cmds;
				data.fds = fds;		
				i++;
				data.size = i;
			}
			cmds[i] = NULL;
			i = 0;

			
			ft_cmd_in_pipe(&data, shell);
			//write(2,"2\n",2);
			//print_cmds(&data);
			free_data(&data);
			str++;
		}
}
