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

int     ft_putchar(int c)
{
    return (write(1, &c, 1));
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    // char str[1000];

    // struct termios term;
    // char *term_name = "xterm-256color";

    // tcgetattr(0, &term);

    // term.c_lflag &= ~(ECHO);
    // term.c_lflag &= ~(ICANON);
    // //term.c_lflag &= ~(ISIG);
	// tcsetattr(0, TCSANOW, &term);
    // term.c_cc[VMIN] = 1; // минимально сколько символов счиатть
    // term.c_cc[VTIME] = 0;   //скольо ждать

    // tgetent(0, term_name);

    // tputs(save_cursor, 1, ft_putchar);
    // int pos;
    // pos = -1;
    // do
    // {
    //     //iostl(0, FIONREAD, &n);
    //     int l = read(0, str, 100);
    //     str[l] = 0;
    //     if (pos == -1)
    //     {
    //         pos = l;
    //     }

    //     if (!ft_strcmp(str, "\e[A"))
    //     {
    //         tputs(restore_cursor, 1 , ft_putchar);
    //         tputs(tigetstr("ed"), 1 , ft_putchar);
    //         //printf("up\n");
    //         write(1,"up",2);
    //     }
    //     else if (!ft_strcmp(str, "\e[B"))
    //     {
    //         tputs(restore_cursor, 1 , ft_putchar);
    //         tputs(tigetstr("ed"), 1 , ft_putchar);
    //         write(1,"down",4);

    //         //printf("down\n");

    //     }
    //     else if (!ft_strcmp(str, "\e[D"))
    //     {
    //         if (pos > 0)
    //         {
    //             tputs(cursor_left, 1, ft_putchar);
    //             pos--;
    //         }
    //         //tputs(tigetstr("ed"), 1 , ft_putchar);
    //         //write(1,"left",4);

    //         //printf("down\n");

    //     }
    //     else if (!ft_strcmp(str, "\e[C"))
    //     {
    //         if (pos + 1 < l)
    //         {
    //             tputs(cursor_right, 1, ft_putchar);
    //             pos++;
    //         }   
           
    //         //tputs(tigetstr("ed"), 1 , ft_putchar);
    //         //write(1,"right",4);

    //         //printf("down\n");
    //     }
    //     else if (!ft_strcmp(str, "\177") && !ft_strcmp(str, "\177"))
    //     {
    //         //
    //         tputs(cursor_left, 1, ft_putchar);
    //         tputs(tgetstr("dc",0), 1 , ft_putchar);
    //         //tputs(delete_character, 1 , ft_putchar);
    //     }
    //     else
    //         write(1, str , l);

    // }while(ft_strcmp(str, "\n"));
    
    // write(1, "\n", 1);
        

    //char *str = key_right;

    t_shell shell;

    ft_init_shell(&shell, envp);
    get_line(&shell);
}
