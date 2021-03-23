/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 02:56:03 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/23 02:56:13 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

static int ft_not_valid_unset(char *str)
{
    write(2, "unset: ", 7);
    write(1,"'",1);
    write(2, str, ft_strlen(str));
    write(1,"'",1);
    write(2, ": not a valid identifier\n", 25);
    return (1);
}

int ft_check_unset(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((i == 0) && (ft_isdigit(str[i]) || !ft_isalpha(str[i])))
            return (ft_not_valid_unset(str));
        if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
            return (ft_not_valid_unset(str));
        i++;
    }
    return (0);
}


int ft_envp_unset(char *str, char ***envp)
{
    char **arr;
    int id;

    arr = *envp;
    if (ft_find_envp(str, *envp) == NULL)
        return (0);
    id = ft_find_envp_id(str,*envp);
    ft_del_str_ind(envp,id);
    return (0);
}

int ft_export_unset(char *str, char ***export)
{
    int id;

    if (ft_find_envp(str, *export) == NULL)
        return (0);
    id = ft_find_envp_id(str,*export);
    ft_del_str_ind(export,id);
    return (0);
}

int ft_unset_envp_export(char *str, char ***export, char ***envp)
{
    if (ft_check_unset(str) == 1)
        return (1);
    if (ft_envp_unset(str, envp) == 1)
    {
        ft_putstr_fd("ERROR!\n", 2); //malloc
        return (1);
    }

    if (ft_export_unset(str, export) == 1)
    {
        ft_putstr_fd("ERROR!\n", 2); //malloc
        return (1);
    }
    return(0);
}

void ft_unset(char **argv,char ***envp, char ***export)
{
    int i;
    int len;

    i = 0;
    len = ft_arrlen(argv);
    if (len == 0)
        return;
    else
    {
        while (argv[i])
        {
            ft_unset_envp_export(argv[i], export, envp);
            i++;
        }
        //ft_bubble_sort(*export,(t_arrinfo){ft_arrlen(*export),8},ft_str_cmp,ft_swap_str);
    }
}