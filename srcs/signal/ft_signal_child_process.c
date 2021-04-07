/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_child_process.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 01:10:55 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/02 01:11:15 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	ft_signal_cltr_c(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_signal = 130;
}

static	void	ft_signal_quit(int sig)
{
	write(1, "\b\b  \b\b", 6);
	write(1, "Quit : ", 7);
	ft_putnbr_fd(sig, 1);
	write(1, "\n", 1);
	g_signal = 131;
}

void			ft_signal_child_process(void)
{
	signal(SIGINT, ft_signal_cltr_c);
	signal(SIGQUIT, ft_signal_quit);
}
