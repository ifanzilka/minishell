/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gang_of_find_lens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:35 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 20:29:36 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char *skip_redirection(char *str)
{
	str++;
	while (*str && *str == ' ')
		str++;
	while (*str && not_one_of_the_set(*str, " |;"))
	{
		if (*str && *str == '"')
		{
			str++;
			while (*str && *str != '"')
			{
				if (*str && *str == '\\')
					str++;
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
		if (*str && not_one_of_the_set(*str, " |;"))
			str++;
	}
	return (str);
}

int	find_cmd_len(char *str)
{
	int len;

	len = 1;
	while (*str && *str == ' ')
		str++;
	while (*str && *str != '|' && *str != ';')
	{
		if (*str && *str == '\'')
		{
			str++;
			while (*str && *str++ != '\'')
				;
		}
		else 
		{
			if (*str && *str == '"')
			{	
				str++;
				while (*str && *str != '"')
					str++;
			}
			else
			{
				if (*str && *str && *str == ' ')
				{
					while (*str && *str == ' ')
						str++;
					if (*str != '>' && *str != '<')
						len++;
					else
						str = skip_redirection(str);
				}
				else
					str++;
			}
		}
	}
	if (*str == '|' && *(str - 1) && *(str - 1) == ' ')
		len--;
	//printf("len = %d\n", len);
	return (len);
}

int		find_cmds_count(char *str)
{
	int len;

	len = 1;
	while (*str)
	{
		if (*str && *str == '\'')
		{
			str++;
			while (*str && *str != '\'')
				str++;
		}
		if (*str && *str == '"')
		{
			str++;
			while (*str && *str != '"')
				str++;
		}
		if (*str && *str == '|')
			len++;
		if (*str && *str == ';')
			break;
		str++;
	}
	return (len);
}
