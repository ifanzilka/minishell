/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:56:51 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 00:57:13 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_export(char **argv, t_shell *shell)
{
	int	i;
	int	len;

	i = 1;
	len = ft_arrlen(argv);
	if (len == 1)
		ft_print_export(shell->export);
	else
	{
		while (argv[i])
		{
			ft_add_envp_export(argv[i], shell);
			i++;
		}
		ft_bubble_sort(shell->export, ft_arrlen(shell->export), ft_param_str());
	}
	return (0);
}
