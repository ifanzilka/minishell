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

void swap_str (void *p1, void *p2)
{
    char *pp1, *pp2, tmp;

    pp1 = (char *) p1;
    pp2 = (char *) p2;

    tmp = *pp1;
    *pp1 = *pp2;
    *pp2 = tmp;
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

    argv_export = malloc(sizeof (char *) *3);
    argv_export[0] = "hello=love";
    argv_export[1] = "myde=hu";
    argv_export[2] = NULL;

    //printf("!!!old envp:\n");
    //printf("Test : %lu\n",sizeof(char **));
    //ft_env(shell.envp);
    //ft_bubble_sort(shell.envp,ft_arrlen(shell.envp),sizeof (char *),ft_str_cmp,swap_str);

    printf("!!!new envp:\n\n\n");
    //ft_env(shell.envp);
    //ft_env(shell.export);

    ft_env(shell.envp);
    ft_del_str_ind(&shell.envp,0);
    printf("!!!end envp:\n\n\n");

    printf("!!!new envp:\n\n\n");
    ft_env(shell.envp);
    //ft_del_str_ind(&shell.envp,0);
    printf("!!!end envp:\n\n\n");

    //ft_export(NULL,&shell.envp,&shell.export);
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
        char *key = "LOGNAME";
        char *value = ft_find_envp(key,envp);
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
