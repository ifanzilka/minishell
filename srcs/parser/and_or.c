/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:32:55 by exenia            #+#    #+#             */
/*   Updated: 2021/04/12 23:38:43 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*quotes_skip(char *str, char **new_str)
{
	if (*str && *str == '"')
	{
		*new_str = join_symbol(*new_str, *str++);
		while (*str && *str != '"')
		{
			*new_str = join_symbol(*new_str, *str++);
			if (*str && *str == '\\')
			{
				*new_str = join_symbol(*new_str, *str++);
				*new_str = join_symbol(*new_str, *str++);
			}
		}
		*new_str = join_symbol(*new_str, *str++);
	}
	if (*str && *str == '\'')
	{
		*new_str = join_symbol(*new_str, *str++);
		while (*str && *str != '\'')
			*new_str = join_symbol(*new_str, *str++);
		*new_str = join_symbol(*new_str, *str++);
	}
	return (str);
}

char	*token_skip(char *str, char **flags, char **new_str)
{
	if (*str && *str == '|')
	{
		if (*(str + 1) && *(str + 1) == '|')
		{
			*new_str = join_symbol(*new_str, ';');
			str += 2;
			*flags = join_symbol(*flags, '|');
		}
		else
			*new_str = join_symbol(*new_str, *str++);
	}
	if (*str && *str == '&' && *(str + 1) && *(str + 1) == '&')
	{
		*new_str = join_symbol(*new_str, ';');
		str += 2;
		*flags = join_symbol(*flags, '&');
	}
	return (str);
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
		str = quotes_skip(str, &new_str);
		str = token_skip(str, flags, &new_str);
		if (*str && *str == ';')
		{
			new_str = join_symbol(new_str, *str++);
			*flags = join_symbol(*flags, ';');
		}
		if (*str && not_one_of_the_set(*str, "\\'\"&|"))
			new_str = join_symbol(new_str, *str++);
	}
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
			while (*++str && *str != '"')
				if (*str && *str == '\\')
					str += 1;
			str++;
		}
		if (*str && *str == '\'')
		{
			str++;
			while (*++str && *str != '\'')
				str++;
			str++;
		}
		if (*str && not_one_of_the_set(*str, ";\"'\\"))
			str++;
	}
	return (str);
}

char	*check_token(char *str, t_shell *shell)
{
	if (*str == ';')
	{
		while (1)
		{
			if (*str && shell->flags[shell->j] == '|' && g_exit_status == 0)
				str = skip_command(str);
			else if (*str && shell->flags[shell->j] == '&' &&
				g_exit_status != 0)
				str = skip_command(str);
			else
			{
				shell->j++;
				break ;
			}
			shell->j++;
		}
		if (*str)
			str++;
	}
	return (str);
}
