/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:51:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/01 19:51:41 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void ft_signal_cltr_c(int sig)
{
    (void) sig;
    g_exit_status = 1;
    write(1, "\b\b  \b\b", 6);
	write(1, "\n", 1);
    g_exit_status = 1;
    ft_print_shell();
}

static void    ft_signal_quit(int sig)
{
    (void) sig;
    write(1, "\b\b  \b\b", 6);
}

void    ft_signal()
{
    signal(SIGINT, ft_signal_cltr_c);
    signal(SIGQUIT, ft_signal_quit);
}