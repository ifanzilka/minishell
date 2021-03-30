/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:52 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 21:11:21 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

void	print_cmds(t_data *data)
{
	int j;
	int i;

	i = 0;
	j = 0;
	//printf("this fucking string is: %s\n", cmds[0][0]);
	while(data->cmds[i]) // по пайпам
	{
		j = 0;
		while (data->cmds[i][j]) // по командам с аргументами
		{
			printf("%d %s ", j, data->cmds[i][j]);
			j++;
		}
		printf("%d %d %d\n", data->fds[i][0], data->fds[i][1], data->fds[i][2]);
		printf("\n\n");
		i++;
	}
}