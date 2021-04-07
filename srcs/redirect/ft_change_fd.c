/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 23:07:36 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/07 23:25:02 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_change_fd(t_redirect *red, int *fds)
{
	if (fds[0] != 0)
	{
		red->old_std_in = dup(0);
		dup2(fds[0], 0);
		close(fds[0]);
	}
	if (fds[1] != 1)
	{
		red->old_std_out = dup(1);
		dup2(fds[1], 1);
		close(fds[1]);
	}
	if (fds[2] != 2)
	{
		red->old_std_err = dup(2);
		dup2(fds[2], 2);
		close(fds[2]);
	}
	return (0);
}
