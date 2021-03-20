/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:23:42 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/20 14:23:46 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_append_arr(char *str, char ***array)
{

    char **new_array;
    char **old_array;
    int size;
    int i;

    i = 0;
    size = ft_arrlen(*array);
    new_array = malloc(sizeof(char *) * (size + 2));
    if (new_array == NULL)
        return (1);
    if (ft_copy_arr(new_array, *array,size) == 1)
        return (1);
    new_array[size] = ft_strdup(str);
    new_array[size + 1] = NULL;
    i = 0 ;
    old_array = *array;
    *array = new_array;
    ft_free_arr(old_array,size);
    return (0);
}

