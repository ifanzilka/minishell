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

#include <libft.h>
#include <stdio.h>
#include <minishell.h>
#include <fcntl.h>


int main(int argc, char **argv, char **envp)
{

    (void) argc;
    (void) argv;
    (void) envp;

    t_shell shell;
    //printf("1\n");
    ft_init_shell(&shell, envp);
    ft_get_line(argc, argv, &shell);
}
