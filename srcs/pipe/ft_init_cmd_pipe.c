/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 02:50:45 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/01 02:50:50 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int     ft_init_cmd_pipe(t_cmd_pipe *cmd_pipe, int size)
{
    int j;

    j = 0;
    cmd_pipe->old_in = dup(0);
    cmd_pipe->old_out = dup(1);
	cmd_pipe->pipes  = malloc(sizeof(int *) * size - 1);
	while (j < size - 1)
	{
		cmd_pipe->pipes[j] = malloc(sizeof(int) * 2);
		pipe(cmd_pipe->pipes[j]);
		j++;
	}
    return (0);
}