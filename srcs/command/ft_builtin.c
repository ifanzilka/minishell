/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:07:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/29 22:07:06 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int ft_descendant_bultin(char *comand,char **argv, t_shell *shell)
{
    int res;

    res = 0;
    if (ft_strcmp(comand, "echo") == 0)
		res = ft_echo(argv, shell->envp);
	if (ft_strcmp(comand, "cd") == 0)
		res = ft_cd(argv, shell);
	if (ft_strcmp(comand, "pwd") == 0)
		res = ft_pwd(argv, shell->envp);
	if (ft_strcmp(comand, "export") == 0)
		res = ft_export(argv, shell);
	if (ft_strcmp(comand, "unset") == 0)
		res =  ft_unset(argv, &shell->envp, &shell->export);
	if (ft_strcmp(comand, "env") == 0)
		res = ft_env( shell->envp);
	if (ft_strcmp(comand, "exit") == 0)
		res = ft_exit(argv);
    return (res);    
}


int ft_builtin(char *comand,char **argv, t_shell *shell)
{
    
    return (ft_descendant_bultin(comand, argv, shell));

}
