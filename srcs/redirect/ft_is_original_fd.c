/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_original_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 03:23:17 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/07 23:25:31 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_is_original_fd(int *fds)
{
	if (fds[0] == 0 && fds[1] == 1 && fds[2] == 2)
		return (1);
	return (0);
}
