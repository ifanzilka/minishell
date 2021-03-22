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


int ft_not_valid_export(char *str)
{
    write(2, "export: ", 9);
    write(2, str, ft_strlen(str));
    write(2, ": not a valid identifier\n", 25);
    return (1);
}

int ft_check_export(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '=')
    {
        if ((i == 0) && (ft_isdigit(str[i]) || !ft_isalpha(str[i])))
            return (ft_not_valid_export(str));
        if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
            return (ft_not_valid_export(str));
        i++;
    }
    if (str[i] == '=')
        return (0);
    return (1);
}


int ft_add_envp(char *str,char ***export, char ***envp)
{

    if (ft_check_export(str) == 1)
        return (1);
    if (ft_append_arr(str, envp) == 1)
    {
        ft_putstr_fd("ERROR!\n", 2); //malloc
        if ( ft_str_find(str, '=') == 1)
        {
            if (ft_append_arr(str,export) == 1)
                ft_putstr_fd("ERROR!\n", 2); //malloc
        }
    }
    return (0);
}

void ft_export(char **argv,char ***envp, char ***export)
{
    (void) envp;
    int i;
    int len;

    i = 0;
    len = ft_arrlen(argv);
    if (len == 0)
        ft_print_export(*export);
    else
    {
        while (argv[i])
        {
            ft_add_envp(argv[i], export,envp);
            i++;
        }
    }
}
