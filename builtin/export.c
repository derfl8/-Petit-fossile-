/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/06/14 18:15:35 by abegou           ###   ########.fr       */
=======
/*   Updated: 2026/06/15 23:20:02 by abegou           ###   ########.fr       */
>>>>>>> a58458a30f9dc347fa89d6d1ee6dc07e78da311d
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdlib.h>

static char	**env_to_char_sort(t_data *shell)
{
	char	**tab;
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = shell->env;
	tab = ft_calloc(sizeof(char *), nb_var(shell) + 1);
	while (tmp)
	{
		tab[i] = tmp->envinfo;
		tmp = tmp->next;
		i++;
	}
	tab[i] = NULL;
	bubble_sort(tab);
	return (tab);
}

static void	exp_no_arg(t_data *shell)
{
	char	*key;
	char	*value;
	char	**tmp;
	int		i;

	tmp = env_to_char_sort(shell);
	i = 0;
	while (tmp[i])
	{
		key = ft_name_var(tmp[i]);
		if (ft_strchr(tmp[i], '=') != NULL)
		{
			value = ft_cut_env(tmp[i]);
			printf("declare -x %s=", key);
			printf("\"%s\"\n", value);
			free(value);
		}
		else
			printf("declare -x %s\n", key);
		free(key);
		i++;
	}
	free(tmp);
}

static bool	is_valid_key(char *keycheck, int limit)
{
	if (ft_isalpha(*keycheck) == 0 && *keycheck != '_')
		return (false);
	while (*keycheck && limit)
	{
		if (ft_isalnum(*keycheck) == 0 && *keycheck != '_')
			return (false);
		keycheck++;
		limit--;
	}
	return (true);
}

static void	add_env(t_data *shell, char *var)
{
	char	*key;
	char	*value;
	t_env	*new;

	key = ft_name_var(var);
	value = ft_cut_env(var);
<<<<<<< HEAD
	if (update_env(shell->env, key, value))
	{
		free(value);
		free(key);
		return ;
	}
	free(key);
	free(value);
	new = ft_new_env(var);
	if (!new)
		return ;
	ft_add_back_env(&shell->env, new);
=======
	if (ft_strchr(var, '='))
	{
		if (!update_env(shell->env, key, value))
		{
			new = ft_new_env(var);
			if (new)
				ft_add_back_env(&shell->env, new);
		}
	}
	else if (!is_in_env(shell->env, key))
	{
		new = ft_new_env(var);
		if (new)
			ft_add_back_env(&shell->env, new);
	}
	free(key);
	free(value);
>>>>>>> a58458a30f9dc347fa89d6d1ee6dc07e78da311d
	return ;
}

int	ft_export(t_data *shell, char **av)
{
	int	i;
	int	limit;

	i = 1;
	if (!av[1])
		exp_no_arg(shell);
	while (av[i])
	{
		if (ft_strchr(av[i], '=') != NULL)
			limit = ft_strchr(av[i], '=') - av[i];
		else
			limit = ft_strlen(av[i]);
		if (is_valid_key(av[i], limit) == false)
			shell->success_or_failed = 1;
		else
			add_env(shell, av[i]);
		i++;
	}
	shell->success_or_failed = 0;
	return (0);
}
