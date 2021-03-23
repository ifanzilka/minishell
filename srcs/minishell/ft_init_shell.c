/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:22:05 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/22 18:22:06 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char **ft_copy_envp(char **envp)
{
    char **envp_copy;
    int i;
    int len;

    len = ft_arrlen(envp);
    i = 0;
    envp_copy = malloc(sizeof(char *) * (len + 1));
    if (envp_copy == NULL)
        return (NULL);
    envp_copy[len] = NULL;
    while (i < len)
    {
        envp_copy[i] = ft_strdup(envp[i]);
        if (envp_copy[i] == NULL)
            return (NULL);
        i++;
    }
    return (envp_copy);
}

static void ft_add_shell_lvl(char **envp)
{
    char *new;
    char *str_lvl;
    int i;
    int lvl;

    new = "SHLVL=";
    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i],new,6))
        {
            lvl = ft_atoi(envp[i] + 6);
            lvl++;
            free(envp[i]);
            str_lvl = ft_itoa(lvl);
            envp[i] = ft_strjoin(new, str_lvl);
            free(str_lvl);
        }
        i++;
    }

}

void ft_init_shell(t_shell *shell,char **envp)
{
    shell->envp = ft_copy_envp(envp);
    ft_add_shell_lvl(shell->envp);
    shell->export = ft_copy_envp(shell->envp);
    ft_bubble_sort(shell->export, (t_arrinfo){ft_arrlen(shell->export) ,sizeof (char **)},
                   ft_str_cmp, ft_swap_str);
    shell->comands = NULL;
}

