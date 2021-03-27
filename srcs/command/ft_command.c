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

int ft_builtin(char *comand,char **argv, char ***envp, char ***export)
{
    (void) comand;
    (void) argv;
    (void) envp;
    (void) export;
    //fork for command  (change fd )
    return (0);
}

int     ft_command(char *comand,char **argv, char ***envp, char ***export)
{
    char *path;
    (void) export;

    path = ft_find_envp("PATH", *envp);
	if (ft_find_builtins(comand))
		return (ft_builtin(comand, argv, envp, export));
    if (path)
        return (ft_with_path(comand, path, argv, *envp));
    else
        return (ft_dont_path(comand,argv, *envp));
    return (0);
}

