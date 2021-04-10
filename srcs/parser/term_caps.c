/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_caps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:13:06 by exenia            #+#    #+#             */
/*   Updated: 2021/04/10 01:42:27 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_escape(t_term *tc, t_shell *shell)
{
	ft_strcpy(&(tc->str1[0]), "---- I'M BATHMAN! ----");
    while(ft_strcmp(tc->str1, "\n"))
	{
        tc->l = read(0, tc->str1, 999);
        tc->str1[tc->l] = 0;
        if (!ft_strcmp(tc->str1, "\e[A")) //up
			history_up(tc, shell);
        else if (!ft_strcmp(tc->str1, "\e[B")) //down
        	history_down(tc, shell);
        else if (!ft_strcmp(tc->str1, "\e[D"))
			move_left(tc);
        else if (!ft_strcmp(tc->str1, "\e[C"))
			move_right(tc);
        else if (!ft_strcmp(tc->str1, "\177"))
			back_space(tc);
		else if (!ft_strcmp(tc->str1, "\e[H"))
			move_home(tc);
		else if (!ft_strcmp(tc->str1, "\e[F"))
			move_end(tc);
        else if (ft_strcmp(tc->str1, "\n"))
			insert_symbol(tc);
    }    
    write(1, "\n", 1);
}

char *term_caps(t_shell *shell)
{
	t_term	tc;
	char	*str;
	struct	termios	term;

	tc.iter = 0;
	tc.line[tc.iter] = '\0';
    tc.term_name = "xterm-256color";
    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO);
    term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
    term.c_cc[VMIN] = 1; // минимально сколько символов счиатть
    term.c_cc[VTIME] = 0;   //скольо ждать
	tgetent(0, tc.term_name);
	tc.iter = 0;
	check_escape(&tc, shell);
	if ((str = ft_strdup(tc.line)) == NULL)
		malloc_error_exit();
	term.c_lflag |= ECHO;
    term.c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, &term);
	return (str);
}