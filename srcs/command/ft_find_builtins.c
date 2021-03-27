/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:43:32 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/27 15:29:32 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int		ft_find_builtins(char *comand, char **argv, char ***envp, char ***export)
{
	if (ft_strcmp(comand, "echo") == 0)
		return (ft_echo(argv, *envp));
	if (ft_strcmp(comand, "cd") == 0)
		return (ft_cd(argv, *envp));
	if (ft_strcmp(comand, "pwd") == 0)
		return (ft_pwd(argv, *envp));
	if (ft_strcmp(comand, "export") == 0)
		return (ft_export(argv, envp, export));
	if (ft_strcmp(comand, "unset") == 0)
		return (ft_unset(argv, envp, export));
	if (ft_strcmp(comand, "env") == 0)
		return (ft_env(*envp));
	if (ft_strcmp(comand, "exit") == 0)
		return (1);
	return (-1);
}
