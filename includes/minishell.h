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

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/*
**  envp_copy -> is envp
**  comands -> list comand divided with ";"
**
*/


typedef struct		s_shell
{
    char            **envp_copy;
    t_list          *envp_dict;
    t_list          *comands;

}					t_shell;

#endif