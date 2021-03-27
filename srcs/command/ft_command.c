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


//
//static int     ft_comand_not_found(char *cmd)
//{
//    ft_putstr_fd(cmd, 2);
//    ft_putstr_fd(": ", 2);
//    ft_putstr_fd("command not found\n", 2);
//    return (127);
//}



int     ft_command(char *comand,char **argv, char ***envp, char ***export)
{
    char *path;
	int res;


    path = ft_find_envp("PATH", *envp);
	res = ft_find_builtins(comand, argv, envp, export);
	if (res != -1)
		return (res);
    if (path)
        return (ft_with_path(comand, path, argv, *envp));
    else
        return (ft_dont_path(comand,argv, *envp));
    return (0);
}

