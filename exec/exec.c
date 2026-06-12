/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:27:46 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 21:28:47 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

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
