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
#include <fcntl.h>


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

    printf("str : %s\n",argv[0]);

    (void) argc;
    (void) argv;
    (void) envp;
    t_shell shell;
    ft_init_shell(&shell,envp);


  
    char ** argvls = NULL;

    argvls = malloc(sizeof (char *) *3);
    argvls[0] = "/bin/ls";
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
    argv_unset[0] = "PATH";
    argv_unset[1] = "1hello123";
    argv_unset[2] = "1hello12=3";
    argv_unset[3] = "123";
    argv_unset[4] = NULL;

    //ft_command("unset",argv_unset,&shell);

    //ft_print_arr(shell.export);
    //ft_command("export", NULL,&shell.envp,&shell.export);

    char ** argv_echo = NULL;

    argv_echo = malloc(sizeof (char *) *5);
    argv_echo[0] = "n";
    argv_echo[1] = "sdmf";
    argv_echo[2] = NULL;
    argv_echo[3] = NULL;
    argv_echo[4] = NULL;
    int fptr;
    fptr = open("test", O_CREAT|O_RDWR,S_IREAD|S_IWRITE);

    //ft_command("echo",argv_echo, &shell, (t_change_fd){0 , fptr});

    char **argv_exit = malloc(sizeof (char *) *5);
    argv_exit[0] = "exit";
   argv_exit[1] = "1";
   argv_exit[2] = "2";
    argv_exit[3] = NULL;
    argv_exit[4] = NULL;

   // ft_command("exit",argv_exit,&shell, (t_change_fd){0 , 1});
    
    int fd[2];
    int old_in = dup(0);
    int old_out = dup(1);

    pipe(fd);

    dup2(fd[1], 1);
    
    char ** argv_ls = NULL; 
    argv_ls = malloc(sizeof (char *) *5);
    argv_ls[0] = "ls";
    argv_ls[1] = NULL;
    argv_ls[2] = NULL;
    argv_ls[3] = NULL;
    argv_ls[4] = NULL;
    ft_command("ls",argv_ls, &shell, (t_change_fd){0 , 1});
    
    close(fd[1]);
    dup2(old_out, 1);

    
    // int fd2[2];

    // pipe(fd2);


    // dup2(fd2[1],1);

    dup2(fd[0], 0);


    char **argv_grep = NULL;
    argv_grep  = malloc(sizeof (char *) *5);
    argv_grep[0] = "usr/bin/grep";
    argv_grep[1] =  "in";
    argv_grep[2] = NULL;
    argv_grep[3] = NULL;
    argv_grep[4] = NULL;
    ft_command("grep", argv_grep, &shell, (t_change_fd){0 , 1});
    
    
    close(fd[0]);

    dup2(old_in, 0);

    // //close(fd2[1]);
    // dup2(old_out,1);


    // dup2(fd2[0],0);
    // char **argv_wc = NULL;
    // argv_wc  = malloc(sizeof (char *) *5);
    // argv_wc [0] = "wc";
    // argv_wc [1] = "2";
    // argv_wc [2] = NULL;
    // argv_wc [3] = NULL;
    // argv_wc [4] = NULL;
    // ft_command("wc",argv_wc, &shell, (t_change_fd){0 , 1});
    
    // close(fd2[0]);
    // dup2(old_in,0);

    
    //char *argv_ls[3];
    // argv_ls[0] = "ls";
    // argv_ls[1] = "-la";
    // argv_ls[2] = NULL;

    //    char *argv_grep[3];
    // argv_grep[0] = "wc";
    // argv_grep[1] = NULL;
    // argv_grep[2] = NULL;

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
    //     execve("/usr/bin/wc", argv_grep, envp);
    // }
    // close(fd[1]);
    // int a;
    // for(int i = 0; i < 2; i++)
    //     wait(&a);


//     int fptr,oldstdout;
//    char msg[] = "Тестовый пример";
//    /* создание файла */
//    fptr = open("DUMMY.FIL",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
//    if(fptr)
//    {
//       /* создать дополнительный дескриптор для stdout */
//       oldstdout = dup(1);
//       /* перенаправить стандартный вывод в файл, путем
//          дублирования его дескриптора */
//       dup2(fptr,1);
//       /* закрыть файл */
//       close(fptr);
//       /* было перенаправлено в DUMMY.FIL */
//       write(1,msg,strlen(msg));
//       /* восстановить исходный дескриптор stdout */
//       dup2(oldstdout,1);
//       /* закрыть второй дескриптор stdout */
//       close(oldstdout);
//    }
//    else
//    {
//       printf("Ошибка при открытии файла. \n");
//    }


    ft_print_name_shell();
    while (1)
        ;   
}
