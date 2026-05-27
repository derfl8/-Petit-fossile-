/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/27 22:17:39 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdlib.h>

static bool	cd_error(t_data *shell, char **av)
{
	t_env	*tmp;
	char	*path;

	tmp = shell->env;
	if (av[2])
	{
		ft_putendl_fd("Petit Fossile: cd: too many arguments", 2);
		shell->success_or_failed = 1;
		return (true);
	}
	else if (!av[1])
	{
		while (tmp && ft_strncmp("HOME=", tmp->envinfo, 5) != 0)
			tmp = tmp->next;
		if (!tmp)
		{
			ft_putendl_fd("Petit Fossile: cd: HOME not set", 2);
			shell->success_or_failed = 1;
			return (true);
		}
		path = ft_cut_env(tmp->envinfo);
		chdir(path);
		free(path);
	}
	return (false);
}

int	ft_cd(t_data *shell, char **av)
{
	char	*pwd;
	char	*oldpwd;
	t_env	*new;

	pwd = ft_calloc(PATH_MAX, sizeof(char));
	oldpwd = ft_calloc(PATH_MAX, sizeof(char));
	if (!pwd || cd_error(shell, av) == true)
	{
		shell->success_or_failed = 1;
		return (1);
	}
	else
	{
		getcwd(oldpwd, PATH_MAX);
		if (chdir(av[1]) == -1)
		{
			ft_putstr_fd("Petit Fossile: cd: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putendl_fd(": No such file or directory", 2);
			shell->success_or_failed = 1;
			free(pwd);
			free(oldpwd);
			return (1);
		}
		getcwd(pwd, PATH_MAX);
		update_env(shell->env, "PWD", pwd);
		if (update_env(shell->env, "OLDPWD", oldpwd) == false) 
		{
			new = ft_new_env(ft_strjoin("OLDPWD=", oldpwd));
			ft_add_back_env(&shell->env, new);
		}
	}
	shell->success_or_failed = 0;
	free(pwd);
	free(oldpwd);
	return (0);
}
