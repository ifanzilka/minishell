/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:42 by exenia            #+#    #+#             */
/*   Updated: 2021/04/09 03:43:07 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *quotes_parse(char *str, char **cmds, t_shell *shell)
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
			if (*str && *str == '\\')
			{
				str++;
				*cmds = join_symbol(*cmds, *str++);
			}
			else if (*str && *str == '$')
				str = dollar_parse(str, &(*cmds), shell);
			else
				*cmds = join_symbol(*cmds, *str++);
		}
		str++;
	}
	return (str);
}

char	*dollar_parse(char *str, char **cmds, t_shell *shell)
{
	char *env;
	char *tmp;

	env = NULL;
	tmp = *cmds;
	if (*++str == '?')
	{
		if (((*cmds) = ft_strjoin((*cmds), ft_itoa(g_exit_status))) == NULL)
			malloc_error_exit();
		str++;
	}
	else
	{
		while (*str && not_one_of_the_set(*str, " |;\\$\"'?"))
			env = join_symbol(env, *str++);	
		if (((*cmds) = ft_strjoin((*cmds), ft_find_envp_2(env, shell->envp))) == NULL)
			malloc_error_exit();
	}
	free(env);
	free(tmp);	
	return (str);
}

char	*parse_by_space(char *str, char **cmds, t_shell *shell)
{
	if ((*cmds = ft_strdup("")) == NULL)
		malloc_error_exit();
	while (*str && not_one_of_the_set(*str, " |;><"))
	{
		if (*str && (*str == '\'' || *str == '"'))
			str = quotes_parse(str, &(*cmds), shell);
		if (*str && *str == '$' )
			str = dollar_parse(str, &(*cmds), shell);
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

char	*select_open_mode(char *str, int **fds, t_shell *shell,
	char *open_func(char *, int **, t_shell *))
{
	str++;
	while (*str && *str == ' ')
		str++;
	if (!*str || *str == '|' || *str == ';')
		str = parse_error(&(*fds), str, 128);
	else
		str = open_func(str, &(*fds), shell);
	return (str);
}

char	*redirection_parse(char *str, int **fds, t_shell *shell)
{
	while (*str && one_of_the_set(*str, "><"))
	{
		if (!*(str + 1) || *(str + 1) == '|' || *(str + 1) == ';')
			str = parse_error(&(*fds), str + 1, 128);
		if (*str == '>' && *(str+ 1) && *(str + 1) == '>')
			str = select_open_mode(++str, &(*fds), shell, append_open);
		if (*str && *str == '>' && *(str + 1) && *(str + 1) != '>')
			str = select_open_mode(str, &(*fds), shell, write_open);
		if (*str && *str == '<')
			str = select_open_mode(str, &(*fds), shell, read_open);
		while (*str && *str == ' ')
			str++;
	}
	return (str);
}
