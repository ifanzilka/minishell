/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_with_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:04:52 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/25 00:04:55 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int    ft_check_file_in_dir(char *dir, char *file)
{
    struct dirent   *dir_point;
    DIR             *dir_descript;
    size_t          len_file;

    len_file = ft_strlen(file);
    dir_descript = opendir(dir);
    if (dir_descript == NULL)
        return (-1);
    while ((dir_point = readdir(dir_descript)))
    {
        if (len_file == ft_strlen(dir_point->d_name) &&
            ft_strncmp(file,dir_point->d_name,len_file) == 0)
        {
            closedir(dir_descript);
            return (1);
        }
    }
    closedir(dir_descript);
    return (0);
}

char      *ft_find_bin(char *path, char *comand)
{
    char **bins;
    char *dir;
    int i;


    i = 0;
    dir = NULL;
    bins = ft_split(path, ':');
    if (bins == NULL)
        return (NULL);
    while (bins[i])
    {
        if (ft_check_file_in_dir(bins[i],comand) == 1)
        {
            dir = ft_strdup(bins[i]);
            break;
        }
        i++;
    }
    ft_free_arr(bins, ft_arrlen(bins));
    return (dir);
}

char *ft_join_dir(char *dir, char *comand)
{
    char *tmp;
    char *new;

    tmp = ft_strjoin(dir,"/");
    if (tmp == NULL)
        return (NULL);
    new = ft_strjoin(tmp, comand);
    free(tmp);
    return (new);
}

int     ft_comand_not_found(char *comand)
{

    ft_putstr_fd(comand, 2);
    ft_putstr_fd(": command not found\n",2);
    return (127);
}

int     ft_with_path(char *comand, char *path, char **argv, char **envp)
{
    char *dir;
    char *way;
    int res;

    if ((dir = ft_find_bin(path,comand)) != NULL)
    {
        way = ft_join_dir(dir, comand);
        res = ft_fork_and_execve_command(way, argv, envp);
        free(way);
        free(dir);
        return (res);
    }
    if (ft_strncmp("./", comand, 2) != 0)
    {
        return (ft_comand_not_found(comand));
    }
    return (ft_fork_and_execve_command(comand,argv,envp));
    //execve(comand,argv,envp);
    //printf("FJJF!\n");
    return (0);
}

