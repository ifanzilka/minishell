/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 03:33:45 by exenia            #+#    #+#             */
/*   Updated: 2021/04/09 20:50:51 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*double_symbol_error(char *str)
{
	if (!*str)
		print_syntax_error(10);
	else if (*str == '&' && *(str + 1) == '&')
		print_syntax_error(777);
	else if (*str == '|' && *(str + 1) == '|')
		print_syntax_error(888);
	else if (*str == ';' && *(str + 1) == ';')	
		print_syntax_error(999);
	else
		print_syntax_error(*str);
	return (NULL);	
}

char	*error_near_token(char *str, int command)
{
	if (command == 0 && one_of_the_set(*str, ";|&"))
	{
		if (*str == '&' && *(str + 1) == '&')
			print_syntax_error(777);
		else if (*str == '|' && *(str + 1) == '|')
			print_syntax_error(888);
		else if (*str == ';' && *(str + 1) == ';')
			print_syntax_error(999);
		else
			print_syntax_error(*str);
		return (NULL) ;
	}
	if (*str == '>' && *(str + 1) == '>')
		str += 2;
	else if (*str == '|' && *(str + 1) == '|')
		str += 2;
	else if (*str == '&' && *(str + 1) == '&')
		str += 2;
	else
		str++;
	while (*str && *str == ' ')
		str++;
	if (!*str || one_of_the_set(*str, "><|;&"))
		return (double_symbol_error(str));	
	return (str);
}

char	*skip_quotes(char *str, int *command)
{
	if (*str && *str == '"')
	{
		*command = 1;
		while (*++str && *str != '"')
			if (*str && *str == '\\')
				str++;
		str++;
	}
	if (*str && *str == '\'')
	{
		*command = 1;
		while (*++str && *str != '\'')
			;
		str++;
	}
	return (str);
}

int		syntax_error_detect(char *str)
{
	int command;

	command = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		str = skip_quotes(str, &command);
		if (*str && not_one_of_the_set(*str, "><|&;"))
			command = 1;
		if (*str && one_of_the_set(*str, "><|;&"))
		{
			if (!(str = error_near_token(str, command)))
				return (1);
			command = 0;
		}
		if (*str)
			str++;
	}
	return (0);
}
