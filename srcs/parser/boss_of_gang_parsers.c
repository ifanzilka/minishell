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

	
	t_cmd_pipe  cmd_pipe;
	

	if (data.size == 1)
	{
		shell->status = ft_command(data.cmds[i][0], data.cmds[i], shell, data.fds[i]);
	}
	else
	{
		ft_init_cmd_pipe(&cmd_pipe, data.size);	
		while (i < data.size)
		{
			// if (i == 0)
			// {
			// 	dup2(pipes[i][1], 1);
			// }

			// if (i > 0)
			// {
			// 	dup2(pipes[i - 1][0], 0);

			// 	if (i  < data.size - 1)
			// 	{
			// 		dup2(pipes[i][1], 1);		
			// 	}
			// }

			// 	if (i == data.size - 1)
			// 	{
			// 		close(pipes[i - 1][0]);
			// 		dup2(old_out, 1);
			// 	}
			//write(2,"1\n",2);

			//if () если есть редирект нужно сделать так чтобы и заридеректилось и запайапало

			ft_before_cmd(&cmd_pipe,i, data.size);
			shell->status = ft_command(data.cmds[i][0], data.cmds[i], shell, data.fds[i]);
			ft_after_cmd(&cmd_pipe,i, data.size);

			// if (shell->status != 0)
			// {
			// 		dup2(old_out, 1);
			// 		dup2(old_in, 0);
			// 		break;
			// }
			// if (i == 0)
			// {
			// 	close(pipes[i][1]);
			// }

			// if (i > 0)
			// {
			// 	close(pipes[i - 1][0]);
				
			// 	if (i  < data.size - 1)
			// 	{
			// 		close(pipes[i][1]);		
			// 	}
			// }
			i++;
		}
	}
	//write(2,"2\n",2);
	//print_cmds(&data);
}
