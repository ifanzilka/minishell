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

static int    ft_check_file_in_dir(char *dir, char *file)
{
    struct dirent *dir_point;
    DIR *dir_descript;
    size_t len_file;

    len_file = ft_strlen(file);
    dir_descript = opendir(dir);
    if (dir_descript == NULL)
        return (-1);
    while ((dir_point = readdir(dir_descript)))
    {
        if (len_file == ft_strlen(dir_point->d_name) && ft_strncmp(file,dir_point->d_name,len_file) == 0)
        {
            closedir(dir_descript);
            return (1);
        }
    }
    closedir(dir_descript);
    return (0);
}

static int     ft_comand_not_found(char *cmd)
{
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd("command not found\n", 2);
    return (127);
}

int     ft_find_bin(char *path, char *comand,char **argv, char **envp)
{
    char **bins;
    int i;
    //pid_t pid;
    (void) comand;
    (void) argv;
    (void) envp;

    i = 0;
    bins = ft_split(path, ':');
    if (bins == NULL)
        return (1);
    while (bins[i])
    {
        if (ft_check_file_in_dir(bins[i],comand) == 1)
        {
            printf("Dir bins : %s\n",bins[i]);
            return (0);
        }
      //ft_putstr_fd(bins[i],1);
      //write(1,"\n",1);
        i++;
    }
    return (0);
}

int     ft_command(char *comand,char **argv, char **envp)
{
    struct stat sb;
    char *path;
    char *errorbuf;
    int res;
    int res_stat;


    res = 0;
    path = ft_find_envp("PATH",envp);
    res_stat = stat("./libft", &sb);
    if (res_stat == 0)
    {
        if (sb.st_mode & S_IFDIR)
        {
            printf("IS DIR!!!\n");
        }
        if (sb.st_mode & S_IFIFO)
        {
            printf("IS FIFO!!!\n");
        }

    }
    else if (res_stat == -1)
    {
        errorbuf = strerror(errno);
        ft_putstr_fd(errorbuf,2);
        write(2, "\n",1);

    }
//
//    if (ft_strncmp(comand,"./",2) == 0)
//        return (ft_current_dir(comand,argv,envp));
    if (path)
    {
        ft_find_bin(path,comand,argv,envp);
        printf("good!\n");
        res = execve("./libft", argv, envp);
        if (res == -1)
        {
            errorbuf = strerror(errno);
            ft_putstr_fd(errorbuf,2);
            write(2, "\n",1);
            return (ft_comand_not_found(comand));
        }

    }
    else
    {
        res = execve(comand, argv, envp);
        if (res == -1)
        {
            errorbuf = strerror(errno);
            ft_putstr_fd(errorbuf,2);
            write(2, "\n",1);
            return (127);
        }
    }
    return (0);
}

