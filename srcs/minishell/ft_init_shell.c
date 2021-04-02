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

static char **ft_copy_envp(char **envp)
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

static void ft_add_shell_lvl_cmd(int lvl, t_shell *shell)
{
    char *argv_un[3];
	char *shlvl;
	char *num;

	num = ft_itoa(lvl);
    argv_un[0] = "export";
    argv_un[1] = NULL;
    argv_un[2] = NULL;
	shlvl = ft_strjoin("SHLVL=", num);
	argv_un[1] = shlvl;
    ft_command("export", argv_un, shell, shell->fds); 
	free(num);
	free(shlvl);
}

static void ft_add_shell_lvl(char **envp, t_shell *shell)
{
    char *new;
    int i;
    int lvl;

    new = "SHLVL=";
    i = 0;
    while (envp[i])
    {
        if (ft_strnstr(envp[i], new , 6))
        {
            lvl = ft_atoi(envp[i] + 6);
            lvl++;
			ft_add_shell_lvl_cmd(lvl, shell);
            return;
        }
        i++;
    }
	ft_add_shell_lvl_cmd(1, shell);
}


static int ft_add_oldpwd(t_shell *shell)
{
    char *argv_ex[3];
    char *argv_un[3];

    argv_un[0] = "unset";
    argv_un[1] = "OLDPWD";
    argv_un[2] = NULL;
    ft_command("unset", argv_un, shell, shell->fds); 
    argv_ex[0] = "export";
    argv_ex[1] = "OLDPWD";
    argv_ex[2] = NULL;
    ft_command("export", argv_ex, shell, shell->fds); 
    return (0);
}


void ft_init_shell(t_shell *shell, char **envp)
{
    shell->envp = ft_copy_envp(envp);
    shell->export = ft_copy_envp(shell->envp);
	if (!shell->envp || !shell->export)
	{
		ft_print_errno();
		exit(1);
	}
	shell->str_inf.bytes = 8;
	shell->str_inf.fun_cmp =  ft_str_cmp;
	shell->str_inf.fun_swap =  ft_swap_str;
    ft_bubble_sort(shell->export, ft_arrlen(shell->export), shell->str_inf);
	ft_add_shell_lvl(shell->envp,shell);
    shell->fds[0] = 0;
	shell->fds[1] = 1;
	shell->fds[2] = 2;
    ft_add_oldpwd(shell);
    ft_signal();
}

