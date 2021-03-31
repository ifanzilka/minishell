/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:50:55 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/22 17:50:57 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void ft_print_export(char **export)
{
    int i;
    int j;

    i = 0;
    while(export[i])
    {
        j = 0;
        write(1, "declare -x ",11);
        while (export[i][j] && export[i][j] != '=')
        {
            write(1, &export[i][j], 1);
            j++;
        }
        if (export[i][j] == '=')
        {
            write(1, "=", 1);
            write(1, "\"", 1);
            ft_putstr_fd((export[i] + j + 1), 1);
            write(1, "\"", 1);
        }
        write(1, "\n" ,1);
        i++;
    }
}

