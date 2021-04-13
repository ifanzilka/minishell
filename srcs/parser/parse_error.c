/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:52 by exenia            #+#    #+#             */
/*   Updated: 2021/04/12 23:55:51 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	malloc_error_exit(void)
{
	ft_print_errno();
	exit(21);
}

int		print_syntax_error(int symbol)
{
	write(2, "minishell: syntax error near unexpected token `", 47);
	if (symbol == 10)
		write(2, "newline", 7);
	else if (symbol == 999)
		write(2, ";;", 2);
	else if (symbol == 777)
		write(2, "&&", 2);
	else if (symbol == 888)
		write(2, "||", 2);
	else
		write(2, &symbol, 1);
	write(2, "'\n", 2);
	return (1);
}

char	*parse_error(long long int **fds, char *str, int err_code)
{
	errno = 0;
	(*fds)[3] = err_code;
	if (err_code == 128)
	{
		if (!*str)
			(*fds)[4] = 10;
		else
			(*fds)[4] = (int)*str;
	}
	return (str);
}
