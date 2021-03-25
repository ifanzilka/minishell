/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_execve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:52:03 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/25 17:52:07 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

static void ft_descendant(char *comand, char **argv, char **envp)
{
    int res;

    res = execve(comand, argv, envp);
    if (res == -1)
    {
        ft_putstr_fd(comand,2);
        ft_putstr_fd(": ",2);
        ft_print_errno();
        exit(1);
    }
    exit (0);
}


int     ft_fork_and_execve_command(char *comand, char **argv, char **envp)
{
    pid_t pid;
    int status;


    status = 0;
    pid = fork();
    if (pid == 0)
    {
        ft_descendant(comand,argv,envp);
    }
    else if (pid == -1)
    {
        ft_print_errno();
        return (1);
    }
    else
    {
        wait(&status);
    }
    return (WEXITSTATUS(status));
}
