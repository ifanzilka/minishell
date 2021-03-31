/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dont_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:04:29 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/25 00:04:30 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int     ft_is_a_directory(char *comand)
{
    ft_putstr_fd(comand,2);
    ft_putstr_fd(": is a directory",2);
    write(1, "\n", 2);
    return (126);
}

static int     ft_check_directory(char *dir)
{
    struct stat sb;
    int res_stat;

    res_stat = stat(dir, &sb);
    if (res_stat == 0)
    {
        if (sb.st_mode & S_IFDIR)
        {
            return (ft_is_a_directory(dir));
        }
    }
    else if (res_stat == -1)
    {
        ft_print_errno();
        return (127);
    }
    return (0);
}



int     ft_dont_path(char *comand, char **argv, char **envp)
{
    int res;

    if ((res = ft_check_directory(comand)) != 0)
    {
        return (res);
    }
    return (ft_fork_and_execve_command(comand,argv,envp));
}