/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:04:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/31 00:20:50 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>


int main(int argc, char **argv, char **envp)
{
    // struct termios term;
    // char *term_name = "xterm-256color";

    // tcgetattr(0, &term);

    // term.c_lflag &= ~(ECHO);
    // term.c_lflag &= ~(ICANON);
	// tcsetattr(0, TCSANOW, &term);
    // // //term.c_cc[VMIN] = 1;
    // // //term.c_cc[VTIME] = 0;

    // tgetent(0,term_name);

    (void) argc;
    (void) argv;
    (void) envp;

    t_shell shell;

    ft_init_shell(&shell, envp);
    get_line(&shell);
}
