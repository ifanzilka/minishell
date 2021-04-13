/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:20:30 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 00:32:42 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_find_envp_id(char *key, char **envp)
{
	int		i;
	size_t	len;
	int		j;

	len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		j = 0;
		if (ft_strncmp(key, envp[i], len) == 0)
		{
			while (envp[i][j] != 0 && envp[i][j] != '=')
				j++;
			if ((size_t)j == len)
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_find_envp(char *key, char **envp)
{
	char	*value;
	int		i;
	size_t	len;
	int		j;

	len = ft_strlen(key);
	i = 0;
	while (envp[i])
	{
		j = 0;
		if (ft_strncmp(key, envp[i], len) == 0)
		{
			while (envp[i][j] != 0 && envp[i][j] != '=')
				j++;
			if ((size_t)j == len)
			{
				value = ft_strdup((envp[i] + j + 1));
				if (value != NULL)
					return (value);
			}
		}
		i++;
	}
	return (NULL);
}
