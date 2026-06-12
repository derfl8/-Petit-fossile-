/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:52:32 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 21:59:53 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

char	**env_to_char(t_data *shell)
{
	char	**tab;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = shell->env;
	tab = ft_calloc(sizeof(char *), nb_var(shell) + 1);
	while (tmp)
	{
		tab[i] = ft_strdup(tmp->envinfo);
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

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

char	*init_path(t_env *tmp, char *cmd)
{
	int		i;
	char	**path;
	char	*path_tmp;
	char	*backslash;

	i = 0;
	path = ft_split(ft_cut_env(tmp->envinfo), ':');
	while (path[i])
	{
		backslash = ft_strjoin("/", cmd);
		path_tmp = path[i];
		path[i] = ft_strjoin(path[i], backslash);
		free(path_tmp);
		i++;
	}
	free(backslash);
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
	return (path);
}
