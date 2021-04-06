/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gang_of_join_find_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:29:38 by exenia            #+#    #+#             */
/*   Updated: 2021/03/30 20:29:39 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*join_symbol(char *str, char a)
{
	char *new_str;
	int len;

	if (!str)
	{
		if ((new_str = malloc(2)) == NULL)
			malloc_error_exit();
		new_str[0] = a;
		new_str[1] = '\0';
	}
	else
	{
		len = ft_strlen(str);
		if ((new_str = malloc(len + 2)) == NULL)
			malloc_error_exit();
		new_str = ft_strcpy(new_str, str);
		new_str[len] = a;
		new_str[len + 1] = '\0';
	}
	free(str);
	return (new_str);
}

int		not_one_of_the_set(char a, char *set)
{
	while (*set)
		if (a == *set++)
			return (0);
	return (1);
}

int		one_of_the_set(char a, char *set)
{
	while (*set)
		if (a == *set++)
			return (1);
	return (0);
}

char *ft_find_envp_2(char *key, char **envp)
{
    char	*value;
    int		i;
    size_t	len;
    int		j;

	len = ft_strlen(key);
    i = 0;
    while(envp[i])
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
				malloc_error_exit();
            }
        }
        i++;
    }
	if ((value = ft_strdup("")) == NULL)
		malloc_error_exit();
    return (value);
}