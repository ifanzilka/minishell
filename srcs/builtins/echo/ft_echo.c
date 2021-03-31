/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:10:42 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/23 22:10:45 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int ft_len_one_echo()
{
	write(1, "\n", 1);
	return (0);
}

int     ft_echo(char **argv, char **envp)
{
    (void) envp;
    int flag_n;
    int i;

    if (ft_arrlen(argv) == 1)
        return (ft_len_one_echo());
    i = 1;
    flag_n = 1;
    while (argv[i])
    {
        if (i == 1 && ft_strlen(argv[i]) == 2 &&
            ft_strcmp(argv[i], "-n") == 0)
        {
            flag_n = 0;
            i++;
            continue;
        }
        ft_putstr_fd(argv[i], 1);
        if (argv[i + 1])
            write(1," ",1);
        i++;
    }
    if (flag_n == 1)
        write(1, "\n" , 1);
    return (0);
}
