/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:50:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/24 17:50:05 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>


//
//static int     ft_comand_not_found(char *cmd)
//{
//    ft_putstr_fd(cmd, 2);
//    ft_putstr_fd(": ", 2);
//    ft_putstr_fd("command not found\n", 2);
//    return (127);
//}



int     ft_command(char *comand,char **argv, char **envp)
{
    char *path;


    path = ft_find_envp("PATH",envp);

    if (path)
    {
//        ft_find_bin(path,comand,argv,envp);
//        printf("good!\n");
//        res = execve("./libft", argv, envp);
//        if (res == -1)
//        {
//            errorbuf = strerror(errno);
//            ft_putstr_fd(errorbuf,2);
//            write(2, "\n",1);
//            return (ft_comand_not_found(comand));
//        }
        ft_with_path(comand, path, argv, envp);
        //ft_dont_path(comand,argv,envp);
    }
    else
    {
        ft_dont_path(comand,argv,envp);
    }
    return (0);
}

