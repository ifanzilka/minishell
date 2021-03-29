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
#include <libft.h>

int     ft_env(char **envp);
int     ft_export(char **argv,char ***envp, char ***export);
int     ft_unset(char **argv,char ***envp, char ***export);
int     ft_cd(char **argv, char **envp);
int     ft_pwd(char **argv, char **envp);
int     ft_echo(char **argv, char **envp);

static int ft_descendant_bultin(char *comand,char **argv, char ***envp, char ***export)
{
    int res;

    res = 0;
    if (ft_strcmp(comand, "echo") == 0)
		res = ft_echo(argv, *envp);
	if (ft_strcmp(comand, "cd") == 0)
		res = ft_cd(argv, *envp);
	if (ft_strcmp(comand, "pwd") == 0)
		res = ft_pwd(argv, *envp);
	if (ft_strcmp(comand, "export") == 0)
		res = ft_export(argv, envp, export);
	if (ft_strcmp(comand, "unset") == 0)
		res =  ft_unset(argv, envp, export);
	if (ft_strcmp(comand, "env") == 0)
		res = ft_env(*envp);
	if (ft_strcmp(comand, "exit") == 0)
		res = 0;
    return (res);    
}


int ft_builtin(char *comand,char **argv, char ***envp, char ***export)
{
    
    return (ft_descendant_bultin(comand, argv, envp, export));

}
