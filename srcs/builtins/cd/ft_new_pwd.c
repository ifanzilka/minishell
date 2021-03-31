/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:56:46 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/30 20:57:49 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_new_pwd(t_shell *shell)
{
    char *argv_ex[3];
    char *pwd;
    char *pwd_pwd;
    int val;

    if (!(pwd = getcwd(NULL,1024)))
    {
        ft_print_errno();
        return (1);
    }
    else
    {
        val = ft_find_envp_id("PWD", shell->envp);
        if (val != -1)
        {
            pwd_pwd = ft_strjoin("PWD=", pwd);
            argv_ex[0] = "export";
            argv_ex[1] = pwd_pwd;
            argv_ex[2] = NULL;
            ft_command("export", argv_ex, shell, shell->fds);
            free(pwd_pwd);
        }
    }
    free(pwd);
    return (0);
}
