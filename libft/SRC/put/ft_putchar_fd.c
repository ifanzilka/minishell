/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:25:58 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 00:10:04 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ENG
*/

/*
** RUS
**
** Выводит символ ’c’ в заданный файловый
** дескриптор.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
