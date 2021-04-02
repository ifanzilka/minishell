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
**  SHELL
**
*/

/*
**  envp_copy -> is envp
**  comands -> list comand divided with ";"
**
*/

int g_exit_status;

typedef struct		s_shell
{
    int 		    fds[3];
    char            **envp;
    char            **export;
    t_l_list        *history;
    
}					t_shell;

void    ft_init_shell(t_shell *shell,char **envp);
void    ft_print_shell();


typedef struct		s_redirect
{
    int             old_std_in;
    int             old_std_out;
    int             old_std_err;
}					t_redirect;

int     ft_change_fd(t_redirect *red ,int *fds);
int     ft_return_fd(t_redirect *red, int *fds);
int     ft_is_original_fd(int *fds);

typedef struct		s_cmd_pipe
{
    int             **pipes;
    int             old_in;
    int             old_out;
    int             old_err;
}					t_cmd_pipe;

int     ft_init_cmd_pipe(t_cmd_pipe *cmd_pipe, int size);
int     ft_return_standat_fd(t_cmd_pipe *cmd_pipe);

int     ft_before_cmd(t_cmd_pipe *cmd_pipe, int num, int cnt);
int     ft_after_cmd(t_cmd_pipe *cmd_pipe, int num , int cnt);



void ft_print_errno();



int ft_oldpwd( char *oldpwd, t_shell *shell);
int ft_new_pwd(t_shell *shell);

char    *ft_find_envp(char *key, char **envp);
int     ft_find_envp_id(char *key, char **envp);

int     ft_check_export(char *str);
int     ft_add_envp_export(char *str,t_shell *shell);
void    ft_print_export(char **export);
int		ft_find_builtins(char *comand);
int     ft_builtin(char *comand,char **argv, t_shell *shell);
int     ft_env(char **envp);
int     ft_export(char **argv,t_shell *shell);
int     ft_unset(char **argv,char ***envp, char ***export);
int     ft_unset_envp_export(char *str, char ***export, char ***envp);


int     ft_cd(char **argv, t_shell *shell);
int     ft_pwd(char **argv, char **envp);
int     ft_echo(char **argv, char **envp);
int     ft_exit(char **argv);
int     ft_command(char *comand,char **argv, t_shell *shell, int *fds);

int     ft_fork_and_execve_command(char *comand, char **argv, char **envp);

int     ft_dont_path(char *comand, char **argv, char **envp);
int     ft_with_path(char *csomand, char *path, char **argv, char **envp);


t_data 			ft_get_line(int argc, char **argv, char **envp,t_shell *shell);
void			parse(char *str, char **envp, t_shell *shell);


//siganal

int     g_signal;
void    ft_signal();
void    ft_signal_child_process();

#endif