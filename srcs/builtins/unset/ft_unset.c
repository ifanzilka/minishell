/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:59:57 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 15:04:51 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_unset(char **argv, char ***envp, char ***export)
{
	int i;
	int len;

	i = 0;
	len = ft_arrlen(argv);
	if (len == 0)
		return (0);
	else
	{
		while (argv[i])
		{
			ft_unset_envp_export(argv[i], export, envp);
			i++;
		}
	}
	return (0);
}
