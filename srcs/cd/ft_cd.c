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
#include <libft.h>

static int    ft_not_set()
{
    write(2, "cd : HOME not set \n",19);
    return (1);
}

static int     ft_change_dir(char *dir)
{
    char *errorbuf;

    if (chdir(dir) == -1) {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf,2);
        write(2,"\n",1);
        return (1);
    }
    return (0);
}

int     ft_cd(char **argv, char **envp)
{
    char *home;

    home = NULL;
    if (ft_arrlen(argv) >= 1)
    {
        return (ft_change_dir(argv[0]));
    }
    else
    {
        home = ft_find_envp("HOME", envp);
        if (home == NULL)
            return (ft_not_set());
    }
    return (0);
}
