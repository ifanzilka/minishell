/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:50:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/27 15:27:29 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

// static void ft_change_fd(t_)
// {

// }

int     ft_command(char *comand,char **argv, t_shell *shell, t_change_fd fd)
{
    char *path;
    int res;
    int oldstd_in;
    int oldstd_out;

    if (fd.fd_0 != 0 || fd.fd_1 != 1)
    {  
        if (fd.fd_0 != 0)
        {
            oldstd_in = dup(0);
            dup2(fd.fd_0, 0);
            close(fd.fd_0);
        }
        if (fd.fd_1 != 1)
        {
            oldstd_out = dup(1);
            dup2(fd.fd_1, 1);
            close(fd.fd_1);
        }
    }
    path = ft_find_envp("PATH", (shell->envp));
	if (ft_find_builtins(comand))
		res = ft_builtin(comand, argv, &shell->envp, &shell->export);
    if (path)
        res = ft_with_path(comand, path, argv, shell->envp);
    else
        res = ft_dont_path(comand, argv, shell->envp);
    if (fd.fd_0 != 0 || fd.fd_1 != 1)
    {
        if (fd.fd_0 != 0)
        {
            dup2(oldstd_in, 0);
            close(oldstd_in);
        }
        if (fd.fd_1 != 1)
        {
            dup2(oldstd_out, 1);
            close(oldstd_out);
        }
         
    }    
    return (res);
}

