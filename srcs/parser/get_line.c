/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:47 by exenia            #+#    #+#             */
/*   Updated: 2021/04/12 23:57:36 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_data	get_line(t_shell *shell)
{
	char	*str;
	pid_t	parent;

	while (1)
	{
		parent = getppid();
		if (parent == 1)
		{
			ft_print_shell();
			write(1, "exit\n", 5);
			exit(137);
		}
		errno = 0;
		ft_print_shell();
		str = term_caps(shell);
		if (ft_strlen(str) > 0)
			ft_add_history(shell, "history", str);
		if (syntax_error_detect(str))
			;
		else if (errno == 0)
			parse(str, shell);
		else
			ft_print_errno();
		free(str);
	}
}
