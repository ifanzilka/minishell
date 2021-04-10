/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:29 by exenia            #+#    #+#             */
/*   Updated: 2021/04/10 04:06:22 by exenia           ###   ########.fr       */
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

char	*get_new_line(char *str_orig, char **flags)
{
	char *new_str;
	char *str;

	str = str_orig;
	new_str = ft_strdup("");
	*flags = ft_strdup("");
	while (*str)
	{
		if (*str && *str == '\\')
		{
			new_str = join_symbol(new_str, *str++);
			new_str = join_symbol(new_str, *str++);
		}
		if (*str && *str == '"')
		{
			new_str = join_symbol(new_str, *str++);
			while (*str && *str != '"')
			{
				new_str = join_symbol(new_str, *str++);
				if (*str && *str == '\\')
				{
					new_str = join_symbol(new_str, *str++);
					new_str = join_symbol(new_str, *str++);
				}		
			}
			new_str = join_symbol(new_str, *str++);
		}
		if (*str && *str == '\'')
		{
			new_str = join_symbol(new_str, *str++);
			while (*str && *str != '\'')
				new_str = join_symbol(new_str, *str++);
			new_str = join_symbol(new_str, *str++);
		}
		if (*str && *str == '|') 
		{
			if (*(str + 1) && *(str + 1) == '|')
			{
				new_str = join_symbol(new_str, ';');
				str += 2;
				*flags = join_symbol(*flags, '|');
			}
			else
				new_str = join_symbol(new_str, *str++);
		}
		if (*str && *str == '&' && *(str + 1) && *(str + 1) == '&')
		{
			new_str = join_symbol(new_str, ';');
			str += 2;
			*flags = join_symbol(*flags, '&');
		}
		if (*str && *str == ';')
		{
			new_str = join_symbol(new_str, *str++);
			*flags = join_symbol(*flags, ';');
		}
		if (*str && not_one_of_the_set(*str, "\\'\"&|"))
			new_str = join_symbol(new_str, *str++);
	}
	//free(str_orig);
	return (new_str);
}

char	*skip_command(char *str)
{
	str++;
	while (*str && *str != ';')
	{
		if (*str && *str == '\\')
			str += 2;
		if (*str && *str == '"')
		{
			str++;
			while (*str && *str != '"')
			{
				if (*str && *str == '\\')
					str += 1;
				str++;		
			}
			str++;
		}
		if (*str && *str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				str++;		
			str++;
		}
		if (*str && not_one_of_the_set(*str, ";\"'\\"))
			str++;
	}
	return (str);
}

void	parse(char *str, t_shell *shell)
{
	int		i;
	char	***cmds;
	t_data	data;
	int		len;
	int		**fds;
	int m;
	m = 0;

	//сделать зануление
	
	str = get_new_line(str, &(data.flags));
//	printf("new str: |-|%s|-|\n", str);
//	printf("flags: %s\n", data.flags);
//	exit(1);
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
		
		//if (!(data.size == 1 && data.cmds[0][0] && data.cmds[0][0][0] == '\0') || data.cmds[0] == NULL)
		ft_cmd_in_pipe(&data, shell);
		// while(1)
		// ;
		//write(2,"2\n",2);
		//printf("Hello!\n");
		free_data(&data);
		
		//printf("Hello!2\n");
		//printf("status %d\n", g_exit_status);
		if (*str == ';')
		{
				while (1)
				
				{
					//if (!*str)
						//break ;
					if (*str && data.flags[m] == '|' && g_exit_status == 0)
					{
						str = skip_command(str);
						m++;
					}
					else if ( *str && data.flags[m] == '&' && g_exit_status != 0)
					{
						str = skip_command(str);
						m++;
					}
					else
					{
						m++;
						//free(str);
						break ;
					}
					//m++;
				}
			if (*str)
				str++;
		}
	}
	//free(str);
}
