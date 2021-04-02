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

char *cmd_parse(char *str, char ***cmds, int **fds, t_shell *shell)
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
	{
	//	free(data->cmds);
		return ;
	}
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
	//printf("END FREE\n");
}

void	parse(char *str, t_shell *shell)
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
	data.size = 0;
	while (*str && *str != ';')
	{
		fds[i] = (int*)malloc(sizeof(int) * 3);
		fds[i][0] = 0;
		fds[i][1] = 1;
		fds[i][2] = 2;
		//printf("Hello!\n");
		str = cmd_parse(str, &(cmds[i]), &(fds[i]), shell);
		data.cmds = cmds;
		data.fds = fds;		
		i++;
		data.size = i;
	}
	cmds[i] = NULL;
	i = 0;

	
	t_cmd_pipe  cmd_pipe;
	int j;

	j = 0;
	if (data.size == 1)
	{
		g_exit_status = ft_command(data.cmds[i][0], data.cmds[i], shell, data.fds[i]);
		//printf("Status %d\n",g_exit_status);
	}
	else
	{
		ft_init_cmd_pipe(&cmd_pipe, data.size);	
		while (i < data.size)
		{
			
			ft_before_cmd(&cmd_pipe,j, data.size);
			if (ft_is_original_fd(data.fds[j]))  //если есть редирект нужно сделать так чтобы и заридеректилось и запайапало
			{

				g_exit_status = ft_command(data.cmds[j][0], data.cmds[j], shell, data.fds[j]);	
				
			}
			else
			{
				g_exit_status = ft_command(data.cmds[j][0], data.cmds[j], shell, shell->fds);
				//pid_t pid;
				//int status;


				int in;
				int out;
				int err;

				in = dup(0);
				out = dup(1);
				err = dup(2);
				//pid = fork();
				
				
				//if (pid == 0)
    			//{
					
					ft_return_standat_fd(&cmd_pipe);
					g_exit_status = ft_command(data.cmds[j][0], data.cmds[j], shell, data.fds[j]);
					//exit(g_exit_status);
    			//}
				//wait(&status);

					dup2(out,1);
					dup2(in,0);
					dup2(err,2);				
			}
			ft_after_cmd(&cmd_pipe,j, data.size);
			if (g_exit_status != 0)
			{
					write(2,"ok\n",3);
					ft_return_standat_fd(&cmd_pipe);
					j = 0;
			}
			j++;
			i++;
		}
	}
	ft_return_standat_fd(&cmd_pipe);
	//write(2,"2\n",2);
	//print_cmds(&data);
	free_data(&data);
}
