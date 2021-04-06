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

char	*write_open(char *str, int **fd, t_shell *shell)
{
	char *file_name;

	if ((file_name = ft_strdup("")) == NULL)
		malloc_error_exit();
	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[1] != 1)
		close((*fd)[1]);
	(*fd)[1] = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ((*fd)[1] == -1)
		str = parse_error(&(*fd), str, errno);
	free(file_name);
	return (str);
}

char	*append_open(char *str, int **fd, t_shell *shell)
{
	char *file_name;

	if ((file_name = ft_strdup(""))	== NULL)
		malloc_error_exit();
	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[1] != 1)
		close((*fd)[1]);
	(*fd)[1] = open(file_name, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if ((*fd)[1] == -1)
		str = parse_error(&(*fd), str, errno);
	free(file_name);
	return (str);
}

char	*read_open(char *str, int **fd, t_shell *shell)
{
	char *file_name;

	if ((file_name = ft_strdup("")) == NULL)
		malloc_error_exit();
	str = parse_by_space(str, &file_name, shell);
	if ((*fd)[0] != 0)
		close((*fd)[0]);
	(*fd)[0] = open(file_name, O_RDONLY, 0644);
	if ((*fd)[0] == -1)
		str = parse_error(&(*fd), str, errno);
	free(file_name);
	return (str);
}
