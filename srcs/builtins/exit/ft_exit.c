/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:36:21 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 00:49:54 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_check_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static	int	ft_not_num_argv(char *str)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required", 2);
	ft_putstr_fd("\n", 2);
	exit(255);
	return (255);
}

static	int	ft_many_argv(void)
{
	ft_putstr_fd("exit: ", 2);
	ft_putstr_fd("too many arguments", 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int			ft_exit(char **argv)
{
	int		len;
	char	num;

	len = ft_arrlen(argv);
	if (len == 1)
		exit(0);
	if (ft_check_num(argv[1]) == 0)
		return (ft_not_num_argv(argv[1]));
	if (len > 2)
		return (ft_many_argv());
	else if (len == 2)
	{
		num = ft_atoi_overflow(argv[1]);
		exit(num);
	}
	return (0);
}
