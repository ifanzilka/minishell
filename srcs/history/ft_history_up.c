/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:12:18 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 15:29:25 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_history_up(t_shell *shell)
{
	t_l_list	*ll_hist;
	char		*str;

	if (shell->current == NULL)
	{
		shell->current = shell->history;
		return (shell->current->content);
	}
	ll_hist = shell->current;
	if (ll_hist->next == NULL)
		return (NULL);
	else
	{
		str = (shell->current->next->content);
		shell->current = shell->current->next;
	}
	return (str);
}
