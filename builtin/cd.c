/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/27 17:10:07 by abegou           ###   ########.fr       */
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
		return (false);
	}
	else if (!av[1])
	{
		while (tmp && ft_strncmp("HOME=", tmp->envinfo, 5) != 0)
			tmp = tmp->next;
		if (!tmp)
		{
			ft_putendl_fd("Petit Fossile: cd: HOME not set", 2);
			shell->success_or_failed = 1;
			return (false);
		}
		path = ft_cut_env(tmp->envinfo);
		chdir(path);
		free(path);
	}
	return (true);
}

int	ft_cd(t_data *shell, char **av)
{
	char	pwd[PATH_MAX];

	if (cd_error(shell, av) == true)
	{
		getcwd(pwd, PATH_MAX);
		if (chdir(av[1]) == -1)
		{
			ft_putstr_fd("Petit Fossile: cd: ", 2);
			ft_putstr_fd(av[1], 2);
			ft_putendl_fd(": No such file or directory", 2);
			shell->success_or_failed = 1;
			return (1);
		}
		shell->env->envinfo = pwd;
	}
	shell->success_or_failed = 0;
	return (0);
}
