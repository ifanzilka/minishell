/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:21:37 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/18 20:21:38 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>


int ft_not_valid(char *str)
{
    write(2, "export: ", 9);
    write(2, str, ft_strlen(str));
    write(2, ": not a valid identifier\n", 25);
    return (1);
}

int ft_check_export(char *str)
{
    int i;
    char flag;

    flag = 0;
    i = 0;
    while (str[i] && str[i] != '=')
    {
        if ((i == 0) && (ft_isdigit(str[i]) || !ft_isalpha(str[i])))
            return (ft_not_valid(str));
        if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
            return (ft_not_valid(str));
        i++;
    }
    if (str[i] == '=')
        return (0);
    return (1);
}

static int     ft_arrlen(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}

//static void    ft_print_envp(char **envp)
//{
//    int i = 0;
//
//    while(envp[i])
//    {
//        ft_putstr_fd(envp[i],1);
//        write(1, "\n" ,1);
//        i++;
//    }
//}

char **ft_realloc_envp(char *str,char ***envp)
{
    int size;
    int i;
    char **envp_new;

    size = ft_arrlen(*envp);
    i = 0;
    envp_new = malloc(sizeof(char *) * (size + 2));
    if (envp_new == NULL)
        return (NULL);
    while (i < size)
    {
        envp_new[i] = ft_strdup((*envp)[i]);
        i++;
    }
    envp_new[i] = ft_strdup(str);
    envp_new[i + 1] = NULL;
    //free старого
    i = 0;
//    while(i <  size )
//    {
//    char **tmp;
//    tmp = *envp;

//    printf("TYT%s", tmp[i]);
//    write(1, "1\n", 2);
//    while (tmp[i])
//    {
//        write(1, "1\n", 2);
//        free(tmp[i]);
//        i++;
//    }
    //ft_print_envp(*envp);
    //free(*envp);
    return (envp_new);
}



int ft_add_envp(char *str,char ***envp)
{
    int i;
    char **tmp;

    i = 0;
    if (ft_check_export(str) == 1)
        return (1);
    write(1,"new\n",4);
    tmp = *envp;
//    *envp = ft_realloc_envp(str,envp);
    while (tmp[i] != NULL)
    {
        write(1, "1\n", 2);
        free(tmp[i]);
        i++;
    }
    //ft_print_envp(*envp);
    return (1);
}

void ft_export(char **argv,char ***envp)
{
    int i;

    i =0;
    while (argv[i])
    {
        //printf("ITER argv : %d\n",i);
        ft_add_envp(argv[i], envp);
        //ft_print_envp(*envp);
        i++;
    }
}
