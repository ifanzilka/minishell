/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:18:55 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/23 22:18:56 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>


int     ft_pwd(char **argv, char **envp)
{
    char *pwd;
    char *errorbuf;
    (void) envp;
    (void) argv;

    if (!(pwd = getcwd(NULL,1024)))
    {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf,2);
        write(2, "\n",1);
        return (1);
    }
    else
    {
        ft_putstr_fd(pwd,1);
        write(1, "\n",1);
    }
    free(pwd);
    return (0);
}