/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:47 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 20:29:48 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

t_data ft_get_line(int argc, char **argv, char **envp,t_shell *shell)
{
	char buf;
	char *str;
	int i;

	(void)argc;
	(void)argv;
	while (1)
	{
		write(1, "minishell$ ",11);
		str = malloc(1);
		str[0] = '\0';
		while (read(1, &buf, 1) == 1 && buf != '\n')
		{
			i = strlen(str) + 1;
			str = realloc(str, i);
			str[i] = '\0';
			str[i - 1] = buf;
		}
		parse(str, envp, shell);
		free(str);
	}
}
