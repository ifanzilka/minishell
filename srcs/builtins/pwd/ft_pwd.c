/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:57:48 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 00:58:35 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_pwd(char **argv, char **envp)
{
	char	*pwd;

	(void)envp;
	(void)argv;
	if (!(pwd = getcwd(NULL, 1024)))
	{
		ft_print_errno();
		return (1);
	}
	else
	{
		ft_putstr_fd(pwd, 1);
		write(1, "\n", 1);
	}
	free(pwd);
	return (0);
}
