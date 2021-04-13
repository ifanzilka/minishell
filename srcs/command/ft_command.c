/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:50:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 15:18:14 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_command(char *comand, char **argv, t_shell *shell, long long int *fds)
{
	t_redirect	redirect;
	char		*path;
	int			res;

	ft_change_fd(&redirect, fds);
	path = ft_find_envp("PATH", (shell->envp));
	if (ft_find_builtins(comand))
	{
		res = ft_builtin(comand, argv, shell);
	}
	else
	{
		if (path)
			res = ft_with_path(comand, path, argv, shell->envp);
		else
			res = ft_dont_path(comand, argv, shell->envp);
	}
	free(path);
	ft_return_fd(&redirect, fds);
	return (res);
}
