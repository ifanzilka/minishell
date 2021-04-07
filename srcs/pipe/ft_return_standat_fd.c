/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_standat_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 03:07:13 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/01 03:07:14 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_return_standat_fd(t_cmd_pipe *cmd_pipe)
{
	dup2(cmd_pipe->old_in, 0);
	dup2(cmd_pipe->old_out, 1);
	dup2(cmd_pipe->old_err, 2);
	return (0);
}
