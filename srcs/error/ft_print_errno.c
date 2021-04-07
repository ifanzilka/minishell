/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_errno.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:13:13 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/07 23:15:29 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_print_errno(void)
{
	char *errorbuf;

	errorbuf = strerror(errno);
	ft_putstr_fd(errorbuf, 2);
	write(2, "\n", 1);
}
