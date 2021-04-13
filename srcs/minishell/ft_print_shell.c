/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:45:33 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/12 21:24:44 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_print_shell(void)
{
	ft_putstr_fd("minishell", 1);
	if (g_exit_status == 0)
	{
		ft_putstr_fd("\033[32m", 1);
		ft_putstr_fd("(o-_-o)", 1);
		ft_putstr_fd("\033[37m", 1);
	}
	else
	{
		ft_putstr_fd("\033[31m", 1);
		ft_putstr_fd("(＞-＜)", 1);
		ft_putstr_fd("\033[37m", 1);
	}
	ft_putstr_fd("$> ", 1);
}
