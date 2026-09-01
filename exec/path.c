/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 14:52:32 by abegou            #+#    #+#             */
/*   Updated: 2026/06/17 23:13:49 by abegou           ###   ########.fr       */
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

static char	**sub_init_path(char *cmd, char **path)
{
	char	*backslash;
	int		i;
	char	*path_tmp;

	i = 0;
	while (path[i])
	{
		backslash = ft_strjoin("/", cmd);
		path_tmp = path[i];
		path[i] = ft_strjoin(path[i], backslash);
		free(backslash);
		free(path_tmp);
		i++;
	}
	return (path);
}

char	*init_path(t_env *tmp, char *cmd)
{
	int		i;
	char	**path;
	char	*cut_env;

	i = 0;
	cut_env = ft_cut_env(tmp->envinfo);
	path = ft_split(cut_env, ':');
	free(cut_env);
	path = sub_init_path(cmd, path);
	i = is_bin(path);
	if (i != -1)
	{
		cut_env = ft_strdup(path[i]);
		free_tab(path);
		return (cut_env);
	}
	free_tab(path);
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
