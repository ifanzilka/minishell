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

t_data ft_get_line(int argc, char **argv,t_shell *shell)
{
	char buf;
	char *str;
	//int i;

	(void)argc;
	(void)argv;

	int res;
	
	res = 0;
	while (1)
	{
		ft_print_shell();
		//str = malloc (1);
		// str = ft_strdup("");
		// while (read(1, &buf, 1) == 1 && buf != '\n')
		// {
		// 	i = strlen(str) + 1;
		// 	str = realloc(str, i);
		// 	str[i] = '\0';
		// 	str[i - 1] = buf;
		// }

		//str = malloc(1);
		//str[0] = '\0';
		str = ft_strdup("");
		while (((res = read(1, &buf, 1)) == 1 || res == 0) && buf != '\n')
		{
		if (res == 0)
		{
		 	// //printf("cltr-d\n");
			// if (ft_strlen(str) == 0)
			// {
			// 	write(1, "exit\n", 5);
			// 	str = ft_strdup("exit");
			// 	break;	
			// }
		}
		else
			//if (buf != '\0')
				str = join_symbol(str, buf);
		
		}	
		parse(str, shell);
		free(str);
	}
}
