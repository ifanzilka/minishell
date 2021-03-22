/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:20:30 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/22 19:20:41 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char *ft_find_envp(char *key, char **envp)
{
    char *value;
    int i;
    size_t len;
    int j;

    j = 0;
    len = ft_strlen(key);
    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(key, envp[i],len) == 0)
        {
            while (envp[i][j] != 0 && envp[i][j] != '=')
                j++;
            value = ft_strdup((envp[i] + j + 1));
            if (value != NULL)
                return (value);
        }
        i++;
    }
    return (NULL);
}
