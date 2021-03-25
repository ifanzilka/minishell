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
#include <libft.h>


int     ft_echo(char **argv, char **envp)
{
    (void) envp;
    int flag_n;
    int i;

    flag_n = 1;
    i = 0;
    while (argv[i])
    {
        if (i == 0 && ft_strlen(argv[i]) == 2 &&
            ft_strncmp(argv[i], "-n", 2) == 0)
        {
            flag_n = 0;
        }
        ft_putstr_fd(argv[i], 1);
        if (argv[i + 1])
            write(1," ",1);
        i++;
    }
    if (flag_n)
        write(1, "\n" , 1);
    return (0);
}
