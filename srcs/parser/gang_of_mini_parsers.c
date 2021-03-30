/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gang_of_mini_parsers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:42 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 21:10:02 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char *quotes_parse(char *str, char **cmds, char **envp)
{
	if (*str && *str == '\'')
	{
		while (*++str && *str != '\'')
			*cmds = join_symbol(*cmds, *str);
		str++;
	}
	if (*str && *str == '"')
	{
		str++;
		while (*str && *str != '"')
		{
			if (*str && *str == '$')
				str = dollar_parse(str, &(*cmds), envp);
			else
				*cmds = join_symbol(*cmds, *str++);
		}
		str++;
	}
	return (str);
}

char	*dollar_parse(char *str, char **cmds, char **envp)
{
	char *env;
	char *tmp;

	env = NULL;
	while (*++str && not_one_of_the_set(*str, " |;\\$\"'"))
		env = join_symbol(env, *str);
	tmp = *cmds;
	(*cmds) = ft_strjoin((*cmds), ft_find_envp_2(env, envp));
	free(env);
	free(tmp);	
	return (str);
}

char	*parse_by_space(char *str, char **cmds, char **envp)
{
	*cmds = ft_strdup("");
	while (*str && not_one_of_the_set(*str, " |;><"))
	{
		if (*str && (*str == '\'' || *str == '"'))
			str = quotes_parse(str, &(*cmds), envp);
		if (*str && *str == '$' )
			str = dollar_parse(str, &(*cmds), envp);
		if (*str && *str == '\\')
		{
			str++;
			*cmds = join_symbol(*cmds, *str++);
		}
		if (*str && not_one_of_the_set(*str, "$\"'\\ ;|><"))
			*cmds = join_symbol(*cmds, *str++);
	}
	return (str);
}

char	*redirection_parse(char *str, int **fds, char **envp)
{
	char *file_name;

	file_name = ft_strdup("");
	//printf("Hello from redirection parse!\n%s\n", str);
	//printf("fds = %d %d %d\n", (*fds)[0], (*fds)[1], (*fds)[2]);
	while (*str && one_of_the_set(*str, "><"))
	{
		if (*str == '>')
		{
			str++;
			//printf("HELLO again!\n");
			if (*str && *str == '>')
			{
				while (*str && *str == ' ')
					str++;
				str = parse_by_space(str, &file_name, envp);
				if ((*fds)[1] != 1)
					close((*fds)[1]);
				(*fds)[1] = open(file_name, O_CREAT | O_APPEND | O_WRONLY | O_TRUNC, 0655);
			}
			else
			{
				while (*str && *str == ' ')
					str++;
				str = parse_by_space(str, &file_name, envp);
				if ((*fds)[1] != 1)
					close((*fds)[1]);
				(*fds)[1] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0655);
				//printf("HELLOO!!!!!!!!!\n");
			}
		}
		if (*str == '<')
		{
			str++;
			str = parse_by_space(str, &file_name, envp);
			if ((*fds)[0] != 0)
				close((*fds)[0]);
			(*fds)[0] = open(file_name, O_CREAT | O_RDONLY | O_TRUNC, 0655);
		}
		while (*str && *str == ' ')
		str++;
	}
	return (str);
}