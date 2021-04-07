/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 01:38:44 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/23 01:39:16 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int ft_replace(char *str,char *key, char **envp)
{
    int i;
    int len;

    len = ft_strlen(key);
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(key, envp[i], len) == 0)
        {
            free(envp[i]);
            envp[i] = ft_strdup(str);
            if (envp[i] == NULL)
			{
                return (1);
			}
            return (0);
        }
        i++;
    }
	
    return (0);
}

static int ft_envp_apppend(char *str, char ***envp)
{
    char *key;
    int index;

    key = NULL;
    if ((index = ft_str_find(str, '=')) == -1)
        return (0);
    key = ft_substr(str, 0, index);
    if (ft_find_envp_id(key, *envp) == -1)
    {
        if (ft_append_arr(str, envp) == 1)
        {
            ft_print_errno();
            return (1);
        }
    }
    else
    {
        ft_replace(str, key, *envp);
    }
    free(key);
    return (0);
}

static int ft_export_apppend(char *str, t_shell *shell)
{
    char *key;
    int index;

    key = NULL;
    if ((index = ft_str_find(str, '=')) != -1)
    {
        key = ft_substr(str, 0, index);
        if (ft_find_str_in_arr(shell->export, key) == -1)
        {
            if (ft_append_arr(str, &shell->export) == 1)
                ft_putstr_fd("ERROR!\n", 2);
        }
        else
        {
            ft_replace(str, key, shell->export);
        }
    }
    if (ft_find_str_in_arr(shell->export, str) == -1 && ft_find_envp(str,shell->envp) == NULL)
    {
        ft_append_arr(str, &shell->export);
    }
    free(key);
    return (0);
}

int ft_add_envp_export(char *str,t_shell *shell)
{

    if (ft_check_export(str) == 1)
        return (1);
    if (ft_envp_apppend(str, &shell->envp) == 1)
    {	
        ft_print_errno();
        return (1);
    }
    if (ft_export_apppend(str, shell) == 1)
    {
        ft_print_errno();
        return (1);
    }
    return (0);
}