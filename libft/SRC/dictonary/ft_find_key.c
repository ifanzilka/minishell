/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:45:35 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/16 00:45:36 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void                *ft_find_key(t_list *dict, void *key,
                                 int (*cmp)(void *, void *))
{
    t_list  *iter;
    t_dict  *tmp;

    iter = dict;
    while(iter)
    {
        tmp = iter->content;
        if (cmp(tmp->key ,key) == 0)
            return (tmp->value);
        iter = iter->next;
    }
    return (NULL);
}

