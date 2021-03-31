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
#include <libft.h>

char *cmd_parse(char *str, char ***cmds, int **fds, char **envp)
{
	int		len;
	int		i;

	len = find_cmd_len(str);
	i = 0;
	*cmds = (char**)malloc(sizeof(char *) * (len + 1));
	(*cmds)[len] = NULL;
	while (*str && not_one_of_the_set(*str, "|;"))
	{
		while (*str && *str == ' ')
			str++;
		if (!(*str) || one_of_the_set(*str, "|;"))
			break;
		if (*str && one_of_the_set(*str, "><"))
		{
			//printf("Redirection_parse call\n");
			str = redirection_parse(str, &(*fds), envp);  //ВОТ ТУТ!!!!
		}
		else
		{
			str = parse_by_space(str, &((*cmds)[i]), envp);
			i++;
		}
	}
	(*cmds)[i] = NULL;
	if (!(*str) || *str == ';')
		return (str);
	else
		return (++str);
}

void	parse(char *str, char **envp, t_shell *shell)
{
	int		i;
	char	***cmds;
	t_data	data;
	int		len;
	int		**fds;

	i = 0;
	len = find_cmds_count(str) + 1;
	//data = (t_data*)malloc(sizeof(t_data));
	cmds = (char ***)malloc(sizeof(char **) * len);
	fds = (int **)malloc(sizeof(int *) * len);
	//printf("Hello!\n");
	while (*str && *str != ';')
	{
		fds[i] = (int*)malloc(sizeof(int) * 3);
		fds[i][0] = 0;
		fds[i][1] = 1;
		fds[i][2] = 2;
		//printf("Hello!\n");
		str = cmd_parse(str, &(cmds[i]), &(fds[i]), envp);
		data.cmds = cmds;
		data.fds = fds;		
		i++;
		data.size = i;
	}
	cmds[i] = NULL;
	i = 0;

	int **pipes;

	pipes = NULL;
	if (data.size > 1)
	{
		pipes = malloc(sizeof(int *) * data.size - 1);
	}
	int j = 0;

	while (j < data.size - 1)
	{
		pipes[j] = malloc(sizeof(int) * 2);
		j++;
	}

	
	int old_in;
	int old_out;

	old_in = dup(0);
	old_out = dup(1);

	printf("SIZE : %d\n",data.size);
	while (i < data.size)
	{
		if (i == 0)
		{
			// создали пайп
			pipe(pipes[i]);
			//заменяем стандартный
			dup2(pipes[i][1], 1);
		}
		if (i == 1)
		{
			//заменяем стандартный
			dup2(pipes[0][0], 0);
		}
		
		write(2,"1\n",2);
		shell->status = ft_command(data.cmds[i][0], data.cmds[i], shell, data.fds[i]);
		

		if (i == 0)
		{
			close(pipes[0][1]);
			dup2(old_out,1);
		}
		if (i == 1)
		{
			close(pipes[0][0]);
			dup2(old_in,0);
		}



		i++;
	}
	//print_cmds(&data);
}
