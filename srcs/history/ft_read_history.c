/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:15:14 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 15:29:35 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_read_history(t_shell *shell, const char *filename)
{
	char	*str;

	str = NULL;
	shell->fd_history = open(filename, O_RDONLY, 0644);
	shell->history = NULL;
	if (shell->fd_history != -1)
	{
		while (get_next_line(shell->fd_history, &str) == 1)
		{
			ft_l_lst_cr_front(&(shell->history), str);
			str = NULL;
		}
		if (str)
			free(str);
		close(shell->fd_history);
	}
	shell->current = shell->history;
	return (0);
}
