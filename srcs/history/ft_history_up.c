/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:12:18 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/08 16:12:20 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char 	*ft_history_up(t_shell *shell)
{
	t_l_list	*ll_hist;
	char 		*str;

	if (shell->current == NULL)
	{
		printf("1\n");
		shell->current = shell->history;
		return (shell->current->content);
	}
	ll_hist = shell->current;
	if (ll_hist->next == NULL)
		return (NULL);
	else
	{
		printf("2\n");
		str = (shell->current->next->content);
		shell->current = shell->current->next;
	}	
	return (str);
}
