/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/27 12:20:17 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

int	ft_cd(t_data *shell, char **av)
{
	t_env	*tmp;
	char	*path;
	char	pwd[PATH_MAX];

	tmp = shell->env;
	if (av[2][1] == '1')
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
		chdir(path);
		free(path);
	}
	else
	{
		getcwd(pwd, PATH_MAX);
		if ()
		{
			
		}
		chdir(av[1]);
	}
	shell->success_or_failed = 0;
	return (0);
}
