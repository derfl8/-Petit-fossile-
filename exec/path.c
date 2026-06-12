/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:52:32 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 16:48:50 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"
#include <stdio.h>

static int	is_bin(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (access(path[i], X_OK | F_OK) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static char	*init_path(t_env *tmp, char *cmd)
{
	int		i;
	char	**path;
	char	*path_tmp;

	i = 0;
	path = ft_split(ft_cut_env(tmp->envinfo), ':');
	while (path[i])
	{
		path_tmp = path[i];
		path[i] = ft_strjoin(path[i], cmd);
		free(path_tmp);
		i++;
	}
	i = is_bin(path);
	if (i != -1)
	{
		path_tmp = path[i];
		free(path);
		return (path_tmp);
	}
	return (NULL);
}

char	*path_verif(t_env *env, char *cmd)
{
	t_env	*tmp;
	char	*path;

	tmp = env;
	while (tmp && ft_strncmp("PATH=", tmp->envinfo, 5) != 0)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	path = init_path(tmp, cmd);
	if (!path)
		free(path);
	return (NULL);
}
