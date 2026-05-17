/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:27:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/17 18:20:11 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <unistd.h>

int	ft_cd(t_data *shell, char **av)
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
	else if ((av[1][0] == '~' && av[1][1]) || !av[1])
	{
		while (tmp && ft_strncmp("HOME=", tmp->envinfo, 4) != 0)
			tmp = tmp->next;
		path = ft_cut_env(tmp->envinfo);
		chdir(path);
		free(path);
	}
	shell->success_or_failed = 0;
	return (0);
}
