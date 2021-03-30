/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:21:37 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/18 20:21:38 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>



int ft_export(char **argv,char ***envp, char ***export)
{
    int i;
    int len;
    
    i = 1;
    len = ft_arrlen(argv);
    if (len == 1)
        ft_print_export(*export);
    else
    {
        while (argv[i])
        {
            ft_add_envp_export(argv[i], export, envp);
            //ft_putstr_fd("\n",1);
            i++;
        }
        ft_bubble_sort(*export,(t_arrinfo){ft_arrlen(*export),8},ft_str_cmp,ft_swap_str);
    }
    return (0);
}
