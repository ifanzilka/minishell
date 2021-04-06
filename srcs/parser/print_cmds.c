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
void	malloc_error_exit(void)
{
	ft_print_errno();
	exit(21);
}
void	print_syntax_error(int symbol)
{
	write(2, "minishell: syntax error near unexpected token `", 47);
	if (symbol == 10)
		write(2, "newline", 7);
	else
		write(2, &symbol, 1);
	write(2, "'\n", 2);
}

char	*parse_error(int **fds, char *str, int err_code)
{
	//ft_print_errno();
	errno = 0;
	(*fds)[3] = err_code;
	if (err_code == 128)
	{
		if (!*str)
			(*fds)[4] = 10;// 10 - new_line
		else
			(*fds)[4] = (int)*str;
	}
	//print_syntax_error((*fds)[4]);
	return ("");
}