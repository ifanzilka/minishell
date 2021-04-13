/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exenia <exenia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:18:43 by bmarilli          #+#    #+#             */
/*   Updated: 2021/04/13 16:26:09 by exenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_not_set(void)
{
	write(2, "minishell: ", 11);
	write(2, "cd : HOME not set \n", 19);
	return (1);
}

static int	ft_change_dir(char *dir, t_shell *shell)
{
	char	*oldpwd;

	if (!(oldpwd = getcwd(NULL, 1024)))
	{
		ft_print_errno();
		return (1);
	}
	if (chdir(dir) == -1)
	{
		ft_putstr_fd("minishell: cd:", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": ", 2);
		ft_print_errno();
		return (1);
	}
	else
	{
		ft_oldpwd(oldpwd, shell);
		ft_new_pwd(shell);
	}
	free(oldpwd);
	return (0);
}

static int	ft_cd_oldpwd(t_shell *shell)
{
	char *value;

	value = ft_find_envp("OLDPWD", shell->envp);
	if (value == NULL)
	{
		write(2, "minishell: ", 11);
		write(2, "cd : OLDPWD not set \n", 21);
		return (1);
	}
	else
	{
		return (ft_change_dir(value, shell));
	}
}

static int	ft_argv_cd(char **argv, t_shell *shell)
{
	char	*value;
	char	*dir;
	int		res;

	if (ft_strcmp(argv[1], "-") == 0)
		return (ft_cd_oldpwd(shell));
	else
	{
		if (argv[1][0] == '~')
		{
			value = ft_find_envp("HOME", shell->envp);
			if (value == NULL && ft_not_set())
				return (1);
			else
			{
				dir = ft_strjoin(value, (argv[1] + 1));
				res = ft_change_dir(dir, shell);
				free(value);
				free(dir);
				return (res);
			}
		}
	}
	return (ft_change_dir(argv[1], shell));
}

int			ft_cd(char **argv, t_shell *shell)
{
	char	*home;
	int		res;

	home = NULL;
	if (ft_arrlen(argv) > 1)
		return (ft_argv_cd(argv, shell));
	else
	{
		home = ft_find_envp("HOME", shell->envp);
		if (home == NULL)
			return (ft_not_set());
		res = ft_change_dir(home, shell);
		free(home);
		return (res);
	}
	return (0);
}
