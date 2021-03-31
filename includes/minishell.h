/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:40:24 by bmarilli          #+#    #+#             */
/*   Updated: 2021/02/20 14:40:27 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
 #define MINISHELL_H

#include <parser.h> 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <libft.h>

/*
**  envp_copy -> is envp
**  comands -> list comand divided with ";"
**
*/


typedef struct		s_shell
{
    char            **envp;
    char            **export;
    t_l_list        *history;
    t_list          *comands;
    int             status;
}					t_shell;

typedef struct		s_change_fd
{
    int fd_0;
    int fd_1;
}					t_change_fd;

void ft_print_errno();

void ft_init_shell(t_shell *shell,char **envp);
int ft_oldpwd( char *oldpwd, t_shell *shell);
int ft_new_pwd(t_shell *shell);

char    *ft_find_envp(char *key, char **envp);
int     ft_find_envp_id(char *key, char **envp);

int     ft_check_export(char *str);
int     ft_add_envp_export(char *str,char ***export, char ***envp);
void    ft_print_export(char **export);
int		ft_find_builtins(char *comand);
int     ft_builtin(char *comand,char **argv, t_shell *shell);
int     ft_env(char **envp);
int     ft_export(char **argv,char ***envp, char ***export);
int     ft_unset(char **argv,char ***envp, char ***export);
int     ft_cd(char **argv, t_shell *shell);
int     ft_pwd(char **argv, char **envp);
int     ft_echo(char **argv, char **envp);
int     ft_exit(char **argv);
int     ft_command(char *comand,char **argv, t_shell *shell, t_change_fd new_fd);

int     ft_fork_and_execve_command(char *comand, char **argv, char **envp);

int     ft_dont_path(char *comand, char **argv, char **envp);
int     ft_with_path(char *csomand, char *path, char **argv, char **envp);


t_data 			ft_get_line(int argc, char **argv, char **envp,t_shell *shell);
void			parse(char *str, char **envp, t_shell *shell);

#endif