/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:50:42 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 00:56:30 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static	int	ft_not_valid_export(char *str)
{
	write(2, "export: ", 9);
	write(2, "'", 1);
	write(2, str, ft_strlen(str));
	write(2, "'", 1);
	write(2, ": not a valid identifier\n", 25);
	return (1);
}

int			ft_check_export(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if ((i == 0) && (ft_isdigit(str[i]) || !ft_isalpha(str[i])))
			return (ft_not_valid_export(str));
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
			return (ft_not_valid_export(str));
		i++;
	}
	return (0);
}
