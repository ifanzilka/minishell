/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:18:43 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/23 22:18:44 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int    ft_not_set()
{
    write(2, "cd : HOME not set \n", 19);
    return (1);
}

static int     ft_change_dir(char *dir, t_shell *shell)
{
    char *oldpwd;

    if (!(oldpwd = getcwd(NULL,1024)))
    {
        ft_print_errno();
        return (1);
    }
    if (chdir(dir) == -1) {
        ft_print_errno();
        return (1);
    }
    else
    {
        ft_oldpwd(oldpwd, shell);
        ft_new_pwd(shell);
    }
    free(oldpwd);
    return (0);
}

int     ft_cd(char **argv, t_shell *shell)
{
    char *home;
    int     res;
    home = NULL;
    if (ft_arrlen(argv) > 1)
    {
        return (ft_change_dir(argv[1], shell));
    }
    else
    {
        home = ft_find_envp("HOME", shell->envp);
        if (home == NULL)
            return (ft_not_set());
        res = ft_change_dir(home, shell);
        free(home);
		return (res);	
    }
    return (0);
}
