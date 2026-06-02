/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:07:59 by abegou            #+#    #+#             */
/*   Updated: 2026/06/01 23:09:20 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static void	rm_env(t_data *shell, char *key)
{
	t_env	*prev;
	t_env	*cur;
	int		s_key;

	s_key = ft_strlen(key);
	cur = shell->env;
	while (ft_strncmp(key, cur->envinfo, s_key) != 0)
	{
		prev = cur;
		cur = cur->next;
	}
	free(cur->envinfo);
	free(cur);
	return ;
}

int	ft_unset(t_data *shell, char **av)
{
	size_t	nb_arg;
	size_t	i;

	if (!av)
		return (0);
	nb_arg = arg_len(av);
	i = 0;
	while (i++ != nb_arg)
	{
		if (search_env(shell->env, av[i]) == true)
			rm_env(shell, av[i]);
	}
	return (0);
}
