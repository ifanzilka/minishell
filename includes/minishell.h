/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:40:24 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/10 01:28:07 by exenia           ###   ########.fr       */
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
#include <fcntl.h>
#include <fcntl.h>
#include <libft.h>
#include <term.h>

#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <curses.h>
#include <get_next_line.h>

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
    t_l_list		*history;
	t_l_list		*current;
    int				fd_history;
}					t_shell;

void    ft_init_shell(t_shell *shell,char **envp);
void    ft_print_shell();


// history
char			*ft_history_up(t_shell *shell);
char 			*ft_history_down(t_shell *shell);
int				ft_read_history(t_shell *shell, const char *filename);
int 			ft_add_history(t_shell *shell, const char *filename, char *str);

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
    int             **pipes_redirect;
    
    int             old_in;
    int             old_out;
    int             old_err;
}					t_cmd_pipe;

int     ft_init_cmd_pipe(t_cmd_pipe *cmd_pipe, int size);
int 	ft_free_cmd_pipe(t_cmd_pipe *cmd_pipe, int size);
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

int g_forks;

int     ft_cd(char **argv, t_shell *shell);
int     ft_pwd(char **argv, char **envp);
int     ft_echo(char **argv, char **envp);
int     ft_exit(char **argv);
int     ft_command(char *comand,char **argv, t_shell *shell, int *fds);
void    ft_cmd_in_pipe(t_data *data, t_shell *shell);

int     ft_fork_and_execve_command(char *comand, char **argv, char **envp);

int     ft_dont_path(char *comand, char **argv, char **envp);
int     ft_with_path(char *csomand, char *path, char **argv, char **envp);


// t_data 			ft_get_line(int argc, char **argv, char **envp,t_shell *shell);
// void			parse(char *str, char **envp, t_shell *shell);


//siganal

int     g_signal;
void    ft_signal();
void    ft_signal_child_process();


//PARSER


t_data 			get_line(t_shell *shell);
void			parse(char *str, t_shell *shell);
int				find_cmd_len(char *str);
int				find_cmds_count(char *str);
void			print_cmds(t_data *data);
char			*dollar_parse(char *str, char **cmds, t_shell *shell);
char			*parse_by_space(char *str, char **cmds, t_shell *shell);
char			*join_symbol(char *str, char a);
char			*quotes_parse(char *str, char **cmds, t_shell *shell);
int				not_one_of_the_set(char a, char *set);
int				one_of_the_set(char a, char *set);
char 			*ft_find_envp_2(char *key, char **envp);
char			*cmd_parse(char *str, char ***cmds, int **fds, t_shell *shell);
char			*redirection_parse(char *str, int **fds, t_shell *shell);
char			*write_open(char *str, int **fd, t_shell *shell);
char			*append_open(char *str, int **fd, t_shell *shell);
char			*read_open(char *str, int **fd, t_shell *shell);
int				print_syntax_error(int symbol);
char			*parse_error(int **fds, char *str, int err_code);
void			malloc_error_exit(void);

/// TERM_CAPS
typedef struct	s_term
{
	char		line[2000];
	int			iter;
	int			i;
	char		buf[2000];
	char		str1[1000];
	int			l;
    char		*term_name;
}				t_term;
char			*term_caps(t_shell *shell);
void			move_end(t_term *tc);
void			move_home(t_term *tc);
void			move_right(t_term *tc);
void			move_left(t_term *tc);
void			insert_symbol(t_term *tc);
void			back_space(t_term *tc);
void			history_up(t_term *tc, t_shell *shell);
void			history_down(t_term *tc, t_shell *shell);
int     		ft_putchar(int c); // В ЛИБУ!!!!
int				syntax_error_detect(char *str);

#endif