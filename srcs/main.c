/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:04:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/08 20:46:52 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// int     ft_putchar(int c)
// {
//     return (write(1, &c, 1));
// }

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;	
    t_shell shell;

    ft_init_shell(&shell, envp);
    get_line(&shell);
}
