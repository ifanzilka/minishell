/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_current_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:29:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/24 21:29:53 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int     ft_current_dir(char *dir, char **argv, char **envp)
{
    int res;
    char *errorbuf;

    printf("CURRENT DIR %s\n",dir);
    res = execve(dir, argv, envp);
    if (res == -1)
    {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf, 2);
        write(2, "\n",1);
        return (127);
    }
    return (0);
}
