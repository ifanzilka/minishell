/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_str_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:26:03 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/22 19:26:17 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_del_str_ind(char ***array, int index)
{
    char **new;
    int len;
    int i;
    int j;

    i = 0;
    j = 0;
    len = ft_arrlen(*array);
    new = (char **)malloc(sizeof (char *) * len);
    while (j < len)
    {
        if (j == index)
        {
            j++;
            continue;
        }
        //write(1,"1\n",2);
        new[i] = ft_strdup((*array)[i]);
        i++;
        j++;
    }
    new[i] = NULL;
    *array = new;
    ft_free_arr(*array,len);
}