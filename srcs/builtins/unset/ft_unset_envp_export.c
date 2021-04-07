/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset_envp_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:48:06 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/31 22:48:07 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int ft_not_valid_unset(char *str)
{
    write(2, "unset: ", 7);
    write(2,"'",1);
    write(2, str, ft_strlen(str));
    write(2,"'",1);
    write(2, ": not a valid identifier\n", 25);
    return (1);
}

static int ft_check_unset(char *str)
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
static int ft_envp_unset(char *str, char ***envp)
{
    char **arr;
    int id;

    
    arr = *envp;
    if (ft_find_envp_id(str, *envp) == -1)
        return (0);
    id = ft_find_envp_id(str,*envp);
    ft_del_str_ind(envp,id);
    return (0);
}

static int ft_export_unset(char *str, char ***export)
{
    int id;

    if (ft_find_envp_id(str, *export) == -1)
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
        ft_print_errno();
        return (1);
    }
    if (ft_export_unset(str, export) == 1)
    {
        ft_print_errno();
        return (1);
    }
    return(0);
}
