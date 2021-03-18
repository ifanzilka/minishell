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
//#include "libft.h"


void    ft_print_name_shell()
{
    ft_putstr_fd("minishell$", 1);
}
//int	ft_strncmp(const char *s1, const char *s2, size_t n);
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

void    ft_print_envp(char **envp)
{
    int i = 0;

    while(envp[i])
    {
        ft_putstr_fd(envp[i],1);
        write(1, "\n" ,1);
        i++;
    }
}

char *ft_find_envp(char *key, char **envp)
{
    char* value;
    int i;
    size_t len;
    int j;

    j = 0;
    len = ft_strlen(key);
    i = 0;

    while(envp[i])
    {
        if (ft_strncmp(key,envp[i],len) == 0)
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



void ft_execve(char *filename, char **argv, char **envp)
{
    int res;

    //fork
    res = execve(filename,argv,envp);
    if (res == -1)
        printf("Error\n");
}

int     ft_arrlen(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

char **ft_copy_envp(char **envp)
{
    char **envp_copy;
    int i;
    int len;

    len = ft_arrlen(envp);
    i = 0;
    envp_copy = malloc(sizeof(char *) * (len + 1));
    if (envp_copy == NULL)
        return (NULL);
    envp_copy[len] = NULL;
    while (i < len)
    {
        envp_copy[i] = ft_strdup(envp[i]);
        i++;
    }
    return (envp_copy);
}

//void ft_echo(char *s,char **arvg,char *s)
//{
//
//}

//void    ft_export()
//{
//
//}

//void ft_unset()
//{
//
//}
void ft_init_shell(t_shell *shell,char **envp)
{
    shell->envp_copy = ft_copy_envp(envp);
    shell->comands = NULL;

}

void onintr(){       /* sig - номер сигнала  */
    //signal (sig, onintr); /* восстановить реакцию */
    printf("Cltr^c\n");
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    (void) envp;
    t_shell shell;
    ft_init_shell(&shell,envp);

    int bytes;
    char buf[1024];
    char byte = 0;
    int i;
    int status;

    write(2,"hello\n",6);

    char ** argvls = NULL;

    argvls = malloc(sizeof (char *) *3);
    argvls[0] = "ls";
    argvls[1] = "l";
    argvls[2] = NULL;
    pid_t pid;
    pid = fork();

    char ** argv_export = NULL;

    argv_export = malloc(sizeof (char *) *3);
    argv_export[0] = "hello=love";
    argv_export[1] = "myde";
    argv_export[2] = NULL;

    printf("old envp:\n");
    ft_print_envp(envp);
    if (pid == 0)
    {
        //ft_execve("/bin/ls",argvls,envp);
        //printf("GoodBye!\n");
        pid_t pid_child = getpid();
        printf("ПОТОМОК!\n");

        printf("PID CHILD : %d\n",pid_child);


        exit(0);
    }
    else if (pid == -1)
    {
        // обработаь ошибку
        printf("Ошибка при fork!\n");

    }
    else
        {
        //pid_t wait;
        wait(&status); //ждем пока закончится дочерние процессы
        printf("РОДИТЕЛЬ!\n");
        pid_t pid_parent = getpid();
        printf("PID PARENT : %d\n",pid_parent);
        char *key = "LOGNAME";
        char *value = ft_find_envp(key,envp);
        if (value != NULL)
            printf("key %s: value: %s\n",key,value);
        else
            printf("FIND NULL\n");
            ft_export(argv_export,&shell.envp_copy);
            printf("new envp:\n");
            ft_print_envp(envp);
       // signal (SIGINT, onintr);
//        while(1)
//            ;
        }


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
        if (ft_strnstr((buf + i), "env", 3))
        {
            ft_print_envp(envp);
        }
        i++;
    }

}
