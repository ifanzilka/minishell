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

t_data	get_line(t_shell *shell)
{
	char	buf;
	char	*str;
	int		res;
	//char 	bufs

	res = 0;
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
		if ((str = ft_strdup("")) == NULL)
			malloc_error_exit();
		
		//tputs(save_cursor, 1, NULL);

		while (((res = read(1, &buf, 1)) == 1) && buf != '\n' )
		{
			str = join_symbol(str, buf);
			// if (!ft_strcmp(str,key_right))
			// {
			// 	printf("up\n");
			// }
			// write(1,&buf,1);
		}
		if (ft_strlen(str) > 0)
		{
			res = open("bash_history", O_WRONLY | O_APPEND | O_CREAT, 0644);
			write(res, str, ft_strlen(str));
			write(res, "\n", 1);
			close(res);
		}	
		if (errno == 0)	
		{
			//printf("Hello!\n");
			parse(str, shell);
		}
		else
			ft_print_errno();
		//printf("Hello!\n");
		free(str);
	}
}