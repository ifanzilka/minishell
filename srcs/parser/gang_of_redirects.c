/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gang_of_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:11:17 by exenia            #+#    #+#             */
/*   Updated: 2021/04/02 20:25:41 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char *write_open(char *str, int *fd, t_shell *shell)
{
	char *file_name;

	file_name = ft_strdup("");
	str++;
	while (*str && *str == ' ')
		str++;
	str = parse_by_space(str, &file_name, shell);
	if (*fd != 1)
		close(*fd);
	*fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*fd == -1)
	{
		ft_print_errno();
	}
	return (str);
}
char *append_open(char *str, int *fd, t_shell *shell)
{
	char *file_name;

	file_name = ft_strdup("");
	str = str + 2;
	while (*str && *str == ' ')
		str++;
	str = parse_by_space(str, &file_name, shell);
	if (*fd != 1)
		close(*fd);
	*fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	return (str);
}

char *read_open(char *str, int *fd, t_shell *shell)
{
	char *file_name;

	file_name = ft_strdup("");
	str++;
	str = parse_by_space(str, &file_name, shell);
	if (*fd != 0)
		close(*fd);
	*fd = open(file_name, O_CREAT | O_RDONLY | O_TRUNC, 0644);
	return (str);
}
