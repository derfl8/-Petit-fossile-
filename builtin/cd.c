/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/06/14 23:15:06 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static void	cd_home(t_data *shell, char *pwd, char *oldpwd, char *path)
{
	getcwd(oldpwd, PATH_MAX);
	chdir(path);
	getcwd(pwd, PATH_MAX);
	update_env(shell->env, "PWD", pwd);
	oldpwd_update(shell, oldpwd);
	free(path);
	return ;
}

static int	cd_error(t_data *shell, char **av, char *pwd, char *oldpwd)
{
	t_env	*tmp;
	char	*path;

	tmp = shell->env;
	if (av[2])
	{
		ft_putendl_fd("Petit Fossile: cd: too many arguments", 2);
		shell->success_or_failed = 1;
		return (1);
	}
	else if (!av[1])
	{
		while (tmp && ft_strncmp("HOME=", tmp->envinfo, 5) != 0)
			tmp = tmp->next;
		if (!tmp)
		{
			ft_putendl_fd("Petit Fossile: cd: HOME not set", 2);
			shell->success_or_failed = 1;
			return (1);
		}
		path = ft_cut_env(tmp->envinfo);
		cd_home(shell, pwd, oldpwd, path);
		return (2);
	}
	return (0);
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

static bool	cd_hyphen(t_data *shell, char *hyphen, char *pwd, char *oldpwd)
{
	t_env	*tmp;
	char	*path;

	tmp = shell->env;
	if (hyphen[0] == '-' && hyphen[1] == '\0')
	{
		while (tmp && ft_strncmp("OLDPWD=", tmp->envinfo, 7) != 0)
			tmp = tmp->next;
		if (!tmp)
			ft_putendl_fd("Petit Fossile: cd: OLDPWD not set", 2);
		else
		{
			path = ft_cut_env(tmp->envinfo);
			printf("%s\n", path);
			getcwd(oldpwd, PATH_MAX);
			chdir(path);
			getcwd(pwd, PATH_MAX);
			update_env(shell->env, "PWD", pwd);
			oldpwd_update(shell, oldpwd);
			free(path);
		}
		return (true);
	}
	return (false);
}

int	ft_cd(t_data *shell, char **av)
{
	char	*pwd;
	char	*oldpwd;
	int		error;

	pwd = ft_calloc(PATH_MAX, sizeof(char));
	oldpwd = ft_calloc(PATH_MAX, sizeof(char));
	error = cd_error(shell, av, pwd, oldpwd);
	if (!pwd || error == 1)
	{
		free_all_pwd(shell, NULL, oldpwd, 1);
		return (1);
	}
	else if (error == 2)
	{
		free_all_pwd(shell, pwd, oldpwd, 0);
		return (0);
	}
	else if (cd_hyphen(shell, av[1], pwd, oldpwd) == false)
	{
		getcwd(oldpwd, PATH_MAX);
		if (path_check(shell, av[1], pwd, oldpwd) == false)
			return (1);
		getcwd(pwd, PATH_MAX);
		update_env(shell->env, "PWD", pwd);
		oldpwd_update(shell, oldpwd);
	}
	free_all_pwd(shell, pwd, oldpwd, 0);
	return (0);
}
