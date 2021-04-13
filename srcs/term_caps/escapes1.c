/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escapes1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:13:02 by exenia            #+#    #+#             */
/*   Updated: 2021/04/13 00:14:14 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	move_left(t_term *tc)
{
	if (tc->iter > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tc->iter--;
	}
}

void	move_right(t_term *tc)
{
	tc->i = (int)ft_strlen(tc->line);
	if (tc->iter < tc->i)
	{
		tputs(cursor_right, 1, ft_putchar);
		tc->iter++;
	}
}

void	move_home(t_term *tc)
{
	while (tc->iter-- != 0)
		tputs(cursor_left, 1, ft_putchar);
	tc->iter++;
}

void	move_end(t_term *tc)
{
	tc->i = ft_strlen(tc->line);
	while (tc->iter++ < tc->i)
		tputs(cursor_right, 1, ft_putchar);
	tc->iter--;
}

void	ctrl_d_exit(t_term *tc)
{
	write(1, "exit", 4);
	ft_strcpy(&(tc->line[0]), "exit");
	tc->str1[0] = '\n';
	tc->str1[1] = '\0';
}
