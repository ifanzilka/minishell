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

int     ft_strlen_mas_ch(char **array)
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

    len = ft_strlen_mas_ch(envp);
    i = 0;
    envp_copy = malloc(sizeof(char *) * (len + 1));
    if (envp_copy == NULL)
        return (NULL);
    while (i < len)
    {
        envp_copy[i] = ft_strdup(envp[i]);
        i++;
    }
    envp_copy[len] = NULL;
    return (envp_copy);
}

void  ft_add_dict(t_list **envp_dict, void *key,void *value)
{
    t_dict *new;
    t_list *new_l;

    new = ft_cr_dict(key,value);
    if (new == NULL)
        printf("NULL\n");
    new_l = ft_lstnew(new);
    if (new_l == NULL)
        printf("NULL\n");
    ft_lstadd_front(envp_dict,new_l);
    if (envp_dict == NULL)
        printf("NULL\n");
    //write(1,"add\n",4);
}

void print_dict(void  *content)
{
    t_dict *el;

    el = (t_dict*)content;
    //char *key;
    //char *value;
    //write(1,"1",1);
    printf("key: %s \nvalue : %s\n",el->key,el->value);
}
//int  ft_cmp_str(void *s1, void *s2)
//{
//    (void )s1;
//    (void)s2;
//    return (1);
//}
int fun(void *s1,void *s2)
{
    (void) s1;
    (void ) s2;
    int a;
    a = ft_strncmp(s1,s2,ft_strlen(s1));
    return (a);
}


void ft_create_dict_envp(t_list **envp_dict,char **envp)
{
    int i = 0;
    char **sp;
    //printf("ok\n");
    while(envp[i])
    {
        sp = ft_split(envp[i],'=');
        if (sp == NULL)
            printf("NULL\n");
        ft_add_dict(envp_dict,sp[0],sp[1]);

    //        write(1, "1" ,1);
    //        ft_putstr_fd(sp[0],1);
    //        write(1, "\n" ,1);
    //        write(1, "2" ,1);
    //        ft_putstr_fd(sp[1],1);
    //        write(1, "\n" ,1);

        //        ft_putstr_fd(envp[i],1);
        //        write(1, "\n" ,1);
        i++;
    }
    if (envp_dict == NULL)
        printf("NULL\n");
    //ft_lstiter(*envp_dict,print_dict);
    char *value;
    value = NULL;
    value = ft_find_key(*envp_dict,"PAT", fun);
    if (value == NULL)
        printf("DON'T FIND KEY!");
    else
        printf("value : %s\n",value);
}
void ft_init_shell(t_shell *shell,char **envp)
{
    shell->envp_copy = ft_copy_envp(envp);
    shell->envp_dict = NULL;
    shell->comands = NULL;

    ft_create_dict_envp(&shell->envp_dict, envp);


//    printf("COPY!\n");
//    ft_print_envp(shell->envp_copy);
//    printf("COPY END\n");
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    (void) argv;
    (void) envp;

    //t_shell shell;
    //ft_init_shell(&shell,envp);

    int bytes;
    char buf[1024];
    char byte = 0;
    int i;

    //printf("%d\n",ft_strncpm("Hello","Hel",3));
//    printf("ORIG!\n");
//    ft_print_envp(envp);
//    printf("ORIG END\n");

    char ** argvls = NULL;

    argvls = malloc(sizeof (char *) *3);
    argvls[0] = "ls";
    argvls[1] = "-l";
    argvls[2] = NULL;
    int pid;
    pid = fork();
    if (pid == 0)
    {
        ft_execve("/bin/ls",argvls,envp);
        printf("GoodBye!\n");
        exit(0);
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


    //printf("Hello, world\n");
    //int i = 0;
    //while (envp[i])
   //{
     //   printf("S: %s\n", envp[i]);
      //  i++;
    //}
    //ft_putstr_fd("Hello, world!\n",1);
}
