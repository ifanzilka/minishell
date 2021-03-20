/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 17:23:07 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/20 17:23:08 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Example :
**
**
**  int a[] = {1,24,435,3,24,5};
**  ft_bubble_sort(a,(t_arrinfo){6,4},cmp_int,ft_swap_int);
**
**
**  void ft_swap_int(void *a, void *b)
**  {
**        int tmp;
**
**        tmp = *(int *)b;
**      *(int *)b = *(int *)a;
**      *(int *)a = tmp;
**  }
**
**  int cmp_int(void *a, void *b)
**  {
**     return (*(int*)a - *(int*)b);
**  }
**
*/

void    ft_bubble_sort(void *arr, t_arrinfo inf, int (*cmp)(void * ,void *), void (*swap_func)(void*, void*))
{
    int i;
    int j;

    i = 0;
    while (i < inf.len)
    {
        j = 0;
        while (j < inf.len - 1)
        {
            if (cmp(arr + j * inf.bytes, arr + (j + 1) * inf.bytes ) > 0)
            {
                swap_func(arr + (j * inf.bytes), arr + (j + 1) * inf.bytes);
            }
            j++;
        }
        i++;
    }
}