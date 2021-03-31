/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:32 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/27 15:29:32 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_find_builtins(char *comand)
{
	if (ft_strcmp(comand, "echo") == 0)
		return (1);
	if (ft_strcmp(comand, "cd") == 0)
		return (1);
	if (ft_strcmp(comand, "pwd") == 0)
		return (1);
	if (ft_strcmp(comand, "export") == 0)
		return (1);
	if (ft_strcmp(comand, "unset") == 0)
		return (1);
	if (ft_strcmp(comand, "env") == 0)
		return (1);
	if (ft_strcmp(comand, "exit") == 0)
		return (1);
	return (0);
}
