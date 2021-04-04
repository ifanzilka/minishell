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
#include <termios.h>
#include <curses.h>

int main(int argc, char **argv, char **envp)
{
    struct termios term;
    char *term_name = "xterm-256color";

    tcgetattr(0, &term);

    term.c_cflag &= ~(ECHO | ICANON);
    // term.c_cflag &= ~(ICANON);
	 tcsetattr(0, TCSANOW, &term);
    //term.c_cc[VMIN] = 1;
    //term.c_cc[VTIME] = 0;

    tgetent(0,term_name);
    (void) argc;
    (void) argv;
    (void) envp;

    t_shell shell;


    //char            *termtype;
    //char            room_termtype[2048];


    //char *str = key_right;
    //printf("1\n");
    ft_init_shell(&shell, envp);
    ft_get_line(argc, argv, &shell);
}
