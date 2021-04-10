/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:47 by exenia            #+#    #+#             */
/*   Updated: 2021/04/10 01:18:19 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	get_line(t_shell *shell)
{
	//char	buf;
	char	*str;
	//char 	bufs

	while (1)
	{
		pid_t parent = getppid();
		//printf("Parent ID = %d\n",parent);

		if (parent == 1)
		{
			ft_print_shell();
			write(1,"exit\n",5);
			exit(137);
		}
		errno = 0;
		ft_print_shell();
		//if ((str = ft_strdup("")) == NULL)
		//	malloc_error_exit();
		str = term_caps(shell);
		if (ft_strlen(str) > 0)
		{
			// res = open("history", O_WRONLY | O_APPEND | O_CREAT, 0644);
			// write(res, str, ft_strlen(str));
			// write(res, "\n", 1);
			// close(res);
			ft_add_history(shell, "history", str);
			//printf("str up: %s\n",ft_history_up(shell));
			//printf("str up: %s\n",ft_history_up(shell));
			//printf("str up: %s\n",ft_history_up(shell));
			//printf("\n\n");
			//printf("str down: %s\n",ft_history_down(shell));
			//printf("str down: %s\n",ft_history_down(shell));
			//printf("str down: %s\n",ft_history_down(shell));
			//printf("str down: %s\n",ft_history_down(shell));
			//printf("str down: %s\n",ft_history_down(shell));
		}
		if (syntax_error_detect(str))
			;
		else if (errno == 0)
		{	

			parse(str, shell);
			
		}
		else
			ft_print_errno();
		free(str);
	}
}
