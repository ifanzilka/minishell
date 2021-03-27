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
#include<fcntl.h>


void    ft_print_name_shell()
{
    ft_putstr_fd("minishell$", 1);
}



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

   

    char ** argv_unset = NULL;

    argv_unset = malloc(sizeof (char *) *5);
    argv_unset[0] = "1hello12";
    argv_unset[1] = "1hello123";
    argv_unset[2] = "1hello12=3";
    argv_unset[3] = "123";
    argv_unset[4] = NULL;

    


    char *argv_ls[3];
    argv_ls[0] = "ls";
    argv_ls[1] = "-la";
    argv_ls[2] = NULL;

       char *argv_grep[3];
    argv_grep[0] = "grep";
    argv_grep[1] = "in";
    argv_grep[2] = NULL;

    // int fd[2];
    // pipe(fd);

    // pid_t pid;
    // pid = fork ();
    // if (pid == 0)
    // {
    //     dup2(fd[1], 1);
    //     close(fd[0]);
    //     execve("/bin/ls", argv_ls, envp);
    // }
    // pid = fork();
    // if (pid == 0)
    // {
    //     dup2(fd[0], 0);
    //     close(fd[1]);
    //     execve("/usr/bin/grep", argv_grep, envp);
    // }
    // close(fd[1]);
    // int a;
    // for(int i = 0; i < 2; i++)
    //     wait(&a);


    int fptr,oldstdout;
   char msg[] = "Тестовый пример";
   /* создание файла */
   fptr = open("DUMMY.FIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
   if(fptr)
   {
      /* создать дополнительный дескриптор для stdout */
      oldstdout = dup(1);
      /* перенаправить стандартный вывод в файл, путем
         дублирования его дескриптора */
      dup2(fptr,1);
      /* закрыть файл */
      close(fptr);
      /* было перенаправлено в DUMMY.FIL */
      write(1,msg,strlen(msg));
      /* восстановить исходный дескриптор stdout */
      dup2(oldstdout,1);
      /* закрыть второй дескриптор stdout */
      close(oldstdout);
   }
   else
   {
      printf("Ошибка при открытии файла. \n");
   }


    ft_print_name_shell();
    while (1)
        ;   
}
