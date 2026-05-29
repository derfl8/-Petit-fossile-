/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/29 18:46:10 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static void	oldpwd_update(t_data *shell, char *oldpwd)
{
	t_env	*new;

	if (update_env(shell->env, "OLDPWD", oldpwd) == false)
	{
		new = ft_new_env(ft_strjoin("OLDPWD=", oldpwd));
		ft_add_back_env(&shell->env, new);
		free(new);
	}
	return ;
}

static void	cd_home(t_data *shell, char *pwd, char *oldpwd, char *path)
{
	chdir(path);
	getcwd(pwd, PATH_MAX);
	update_env(shell->env, "PWD", pwd);
	oldpwd_update(shell, oldpwd);
	free(path);
	return ;
}

static bool	cd_error(t_data *shell, char **av, char *pwd, char *oldpwd)
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
		getcwd(oldpwd, PATH_MAX);
		path = ft_cut_env(tmp->envinfo);
		cd_home(shell, pwd, oldpwd, path);
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

int	ft_cd(t_data *shell, char **av)
{
	char	*pwd;
	char	*oldpwd;

	pwd = ft_calloc(PATH_MAX, sizeof(char));
	oldpwd = ft_calloc(PATH_MAX, sizeof(char));
	if (!pwd || cd_error(shell, av, pwd, oldpwd) == true)
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
