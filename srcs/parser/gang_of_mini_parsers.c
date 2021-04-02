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
			if (*str && *str == '$')
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
		(*cmds) = ft_strjoin((*cmds), ft_itoa(g_exit_status));
		str++;
	}
	else
	{
		while (*str && not_one_of_the_set(*str, " |;\\$\"'?"))
			env = join_symbol(env, *str++);	
		(*cmds) = ft_strjoin((*cmds), ft_find_envp_2(env, shell->envp));
	}
	free(env);
	free(tmp);	
	return (str);
}

char	*parse_by_space(char *str, char **cmds, t_shell *shell)
{
	*cmds = ft_strdup("");
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

char	*redirection_parse(char *str, int **fds, t_shell *shell)
{
	while (*str && one_of_the_set(*str, "><"))
	{
		if (*str == '>' && *(str+ 1) && *(str + 1) == '>')
			str = append_open(str, &((*fds)[1]), shell);
		if (*str == '>' && *(str + 1) && *(str + 1) != '>')
			str = write_open(str, &((*fds)[1]), shell);
		if (*str == '<')
			str = read_open(str, &((*fds)[0]), shell);
		while (*str && *str == ' ')
			str++;
	}
	return (str);
}
