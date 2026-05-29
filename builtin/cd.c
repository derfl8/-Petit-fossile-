/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/29 14:37:49 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdbool.h>

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

static bool	path_check(t_data *shell, char *path, char *pwd, char *oldpwd)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("Petit Fossile: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
		shell->success_or_failed = 1;
		free(pwd);
		free(oldpwd);
		return (false);
	}
	return (true);
}

static void	oldpwd_update(t_data *shell, char *oldpwd)
{
	t_env	*new;

	if (update_env(shell->env, "OLDPWD", oldpwd) == false)
	{
		new = ft_new_env(ft_strjoin("OLDPWD=", oldpwd));
		ft_add_back_env(&shell->env, new);
	}
}

int	ft_cd(t_data *shell, char **av)
{
	char	*pwd;
	char	*oldpwd;

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
		if (path_check(shell, av[1], pwd, oldpwd) == false)
			return (1);
		getcwd(pwd, PATH_MAX);
		update_env(shell->env, "PWD", pwd);
		oldpwd_update(shell, oldpwd);
	}
	shell->success_or_failed = 0;
	free(pwd);
	free(oldpwd);
	return (0);
}
