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


void    ft_print_name_shell()
{
    ft_putstr_fd("minishell$", 1);
}



void onintr(){       /* sig - номер сигнала  */
    //signal (sig, onintr); /* восстановить реакцию */
    printf("Cltr^c\n");
}


void ft_swap_int(void *a, void *b)
{
    int tmp;

    tmp = *(int *)b;
    *(int *)b = *(int *)a;
    *(int *)a = tmp;
}

int cmp_int(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
}


int main(int argc, char **argv, char **envp)
{
    t_shell shell;
    ft_init_shell(&shell,envp);
    ft_get_line(argc, argv, shell.envp,&shell);
}
