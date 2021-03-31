/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oldpwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:58:42 by bmarilli          #+#    #+#             */
/*   Updated: 2021/03/30 18:58:52 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_oldpwd(char *oldpwd, t_shell *shell)
{
    char *argv_ex[3];
    char *pwds;
    int  o_pw;

    o_pw = ft_find_envp_id("OLDPWD", shell->export);
    if (o_pw != -1)
    {
        pwds = ft_strjoin("OLDPWD=", oldpwd);
        argv_ex[0] = "export";
        argv_ex[1] = pwds;
        argv_ex[2] = NULL;
        ft_command("export", argv_ex, shell, shell->fds); 
        free(pwds);
    }
    return (0);
}
