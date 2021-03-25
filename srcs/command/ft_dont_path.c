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
#include <libft.h>

int     ft_is_a_directory(char *comand)
{
    ft_putstr_fd(comand,2);
    ft_putstr_fd(": is a directory",2);
    write(1, "\n", 2);
    return (126);
}

int     ft_dont_path(char comand, char *argv, char **envp)
{
    struct stat sb;
    char *errorbuf;
    int res;
    int res_stat;


    res = 0;
    res_stat = stat(comand, &sb);
    if (res_stat == 0)
    {
        if (sb.st_mode & S_IFDIR)
            return (ft_is_a_directory(comand));
    }
    else if (res_stat == -1)
    {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf,2);
        write(2, "\n",1);
        return (1);
    }
    res = execve(comand, argv, envp);
    if (res == -1)
    {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf,2);
        write(2, "\n",1);
        return (127);
    }
}
