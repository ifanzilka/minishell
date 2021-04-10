/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:51:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/10 03:50:53 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	void	ft_signal_cltr_c(int sig)
{
	(void)sig;
	g_exit_status = 1;
	write(1, "\n", 1);
	g_exit_status = 1;
	ft_print_shell();
}

static	void	ft_signal_quit(int sig)
{
	(void)sig;
	write(1, "\b\b  \b\b", 6);
}

static	void	ft_sigterm(int sig)
{
	(void)sig;
}

static	void	ft_signal_sigchld(int sig)
{
	(void)sig;
}

void			ft_signal(void)
{
	signal(SIGINT, ft_signal_cltr_c);
	signal(SIGQUIT, ft_signal_quit);
	signal(SIGCHLD, ft_signal_sigchld);
	signal(SIGTERM, ft_sigterm);
}
