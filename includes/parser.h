/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 21:43:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/30 21:43:05 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include "minishell.h"

typedef struct	s_data
{
	char		***cmds;
	int			**fds;
	int			size;
}				t_data;


int				find_cmd_len(char *str);
int				find_cmds_count(char *str);
void			print_cmds(t_data *data);
char			*dollar_parse(char *str, char **cmds, char **envp);
char			*parse_by_space(char *str, char **cmds, char **envp);
char			*join_symbol(char *str, char a);
char			*quotes_parse(char *str, char **cmds, char **envp);
int				not_one_of_the_set(char a, char *set);
int				one_of_the_set(char a, char *set);
char 			*ft_find_envp_2(char *key, char **envp);
char			*cmd_parse(char *str, char ***cmds, int **fds, char **envp);
char			*redirection_parse(char *str, int **fds, char **envp);


#endif
