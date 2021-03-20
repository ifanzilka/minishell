/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:58:46 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/20 13:58:48 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_print_arr(char **arr)
{
    int i;

    i = 0;
    while(arr[i])
    {
        ft_putstr_fd(arr[i], 1);
        write(1, "\n" ,1);
        i++;
    }
}
