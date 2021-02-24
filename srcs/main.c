/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:04:39 by bmarilli          #+#    #+#             */
/*   Updated: 2021/02/22 16:04:40 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <minishell.h>


void    ft_print_name_shell()
{
    ft_putstr_fd("minishell$",1);
}

void ft_pwd()
{
    ft_print_name_shell();
    errno = 0;
    char *pwd;
    if (!(pwd = getcwd(NULL,1024)))
    {
        //malloc error
        char *errorbuf = strerror( errno);
        printf("%s\n",errorbuf);
        return;
    }
    printf("%s\n", pwd);
    free(pwd);
}

void ft_cd(char *path)
{
    errno = 0;
    if (chdir(path) == -1)
    {
        //error
        //perror("");
        char *errorbuf = strerror(errno);
        printf("%s\n",errorbuf);
        return;
    }
    ft_pwd();
}

void    ft_print_char(char **str)
{
    int i = 0;

    while(str[i])
    {
        printf("s : %s\n",str[i]);
        i++;
    }

}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    (void) envp;
    int bytes;
    char buf[1024];
    char byte = 0;
    int i;



    ft_print_char(envp);
    i = 0;
    ft_print_name_shell();
    while ((bytes = read(1,&byte, 1)) >0)
    {
        buf[i] = byte;
        if (byte == '\n' || byte == 0) {
            buf[i + 1] = 0;
            printf("buf : %s\n", buf);
            //return 0;
            break;
        }
        i++;
    }
    i = 0;
    while (buf[i])
    {
        if (ft_strnstr((buf + i), "pwd", 3)) {
            ft_pwd();
        }
        if (ft_strnstr((buf + i), "cd", 2)) {

            i = i + 2;
            int start;
            int end;

            while(buf[i] && buf[i] == ' ')
                i++;
            start = i;
            while(buf[i] && buf[i] != ' ' && buf[i] != '\n')
                i++;
            end = i;

            char *path = ft_substr(buf,start,end - start);

            printf("path : !%s!\n",path);
            ft_cd(path);
        }
        i++;
    }


    //printf("Hello, world\n");
    //int i = 0;
    //while (envp[i])
   //{
     //   printf("S: %s\n", envp[i]);
      //  i++;
    //}
    //ft_putstr_fd("Hello, world!\n",1);
}
