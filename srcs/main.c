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
//void ft_pwd()
//{
//    ft_print_name_shell();
//    errno = 0;
//    char *pwd;
//    if (!(pwd = getcwd(NULL,1024)))
//    {
//        //malloc error
//        char *errorbuf = strerror( errno);
//        printf("%s\n",errorbuf);
//        return;
//    }
//    printf("%s\n", pwd);
//    free(pwd);
//}

//void ft_cd(char *path)
//{
//    errno = 0;
//    if (chdir(path) == -1)
//    {
//        //error
//        perror(NULL);
//        //char *errorbuf = strerror(errno);
//        //printf("%s\n",errorbuf);
//        return;
//    }
//    ft_pwd();
//}

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





void ft_execve(char *filename, char **argv, char **envp)
{
    int res;

    //fork
    res = execve(filename,argv,envp);
    if (res == -1)
        printf("Error\n");
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





void onintr(){       /* sig - номер сигнала  */
    //signal (sig, onintr); /* восстановить реакцию */
    printf("Cltr^c\n");
}


void ft_swap_int(void *a, void *b)
{
    int tmp;

    tmp = *(int *)b;
    *(int *)b = *(int *)a;
    *(int *)a = tmp;
}

int cmp_int(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
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

    //write(2,"hello\n",6);

    char ** argvls = NULL;

    argvls = malloc(sizeof (char *) *3);
    argvls[0] = "ls";
    argvls[1] = "l";
    argvls[2] = NULL;


    char ** argv_export = NULL;

    argv_export = malloc(sizeof (char *) *5);
    argv_export[0] = "hello=love";
    argv_export[1] = "hello123=2";
    argv_export[2] = "hello12=3";
    argv_export[3] = "123";
    argv_export[4] = NULL;



    printf("!!old envp:\n");
    ft_env(shell.export);
    //ft_del_str_ind(&shell.envp,0);
    printf("!!!end envp:\n");


    printf("!!!new envp:\n\n");

    ft_export(argv_export,&shell.envp,&shell.export);
    ft_export(NULL,&shell.envp,&shell.export);

    ft_env(shell.envp);
    write(1,"\n\n",2);
    //ft_env(shell.export);
    printf("!!!end envp:\n");

    char ** argv_unset = NULL;

    argv_unset = malloc(sizeof (char *) *5);
    argv_unset[0] = "1hello12";
    argv_unset[1] = "1hello123";
    argv_unset[2] = "1hello12=3";
    argv_unset[3] = "123";
    argv_unset[4] = NULL;

    printf("!!!UNSET!!!:\n\n");
    ft_unset(argv_unset,&shell.envp,&shell.export);
    ft_env(shell.export);



    //ft_str_bubble_sort(shell.envp,ft_arrlen(shell.envp));

//    int a[] = {1,24,435,3,24,5,1111};
//
//    ft_bubble_sort(a,(t_arrinfo){7,4},cmp_int,ft_swap_int);
//    int gh= 0;
//    while (gh < 7)
//    {
//        printf("%d\n",a[gh]);
//        gh++;
//    }

    //ft_env(shell.export);

    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        //ft_execve("./minishell",NULL,shell.envp);
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
        char *key = "hello12";
        char *value = ft_find_envp(key, shell.envp);
        if (value != NULL)
            printf("key %s: value: %s\n",key,value);
        else
        {
            printf("FIND NULL\n");
        }
        //ft_export(argv_export,&shell.envp);
        //printf("new envp:\n");
        //ft_env(shell.envp);
        
       // signal (SIGINT, onintr);
    //        while(1)
    //            ;
        }

    char **argv_echo;

    argv_echo = NULL;

    argv_echo= malloc(sizeof (char *) * 3);
    argv_echo[0] = "n";
    argv_echo[1] = "sdf";
    argv_echo[2] = NULL;

    ft_echo(argv_echo,NULL);

    char **argv_cmd;

    argv_cmd = NULL;

    argv_cmd= malloc(sizeof (char *) * 3);
    argv_cmd[0] = "ls";
    argv_cmd[1] = "-la";
    argv_cmd[2] = NULL;

    printf("CMD!!!\n");
    ft_command("./ls",argv_cmd, shell.envp);

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
            ft_pwd(NULL,NULL);
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
            char **argv_cd;

            argv_cd = NULL;
            argv_cd = malloc (sizeof (char *) * 2);
            argv_cd[0] = path;
            argv_cd[1] = NULL;
            ft_cd(argv_cd,shell.envp);
            ft_pwd(NULL,NULL);
        }
        if (ft_strnstr((buf + i), "env", 3))
        {
            ft_env(envp);
        }
        i++;
    }

}
