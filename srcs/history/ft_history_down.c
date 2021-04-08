/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:16:55 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/08 16:16:59 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char 	*ft_history_down(t_shell *shell)
{
	t_l_list	*ll_hist;
	char 		*str;

	if (shell->current == NULL)
	{
		return (NULL);
	}
	ll_hist = shell->current;
	if (ll_hist->prev == NULL)
		return (NULL);
	else
	{
		str = (shell->current->prev->content);
		shell->current = shell->current->prev;
	}	
	return (str);
}
