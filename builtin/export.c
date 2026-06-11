/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
/*   Updated: 2026/06/11 17:49:22 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static char	**env_to_char(t_data *shell)
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

	tmp = env_to_char(shell);
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
		if (ft_isalnum(*keycheck) || *keycheck != '_')
			return (false);
		keycheck++;
		limit--;
	}
	return (true);
}

static void	add_env(t_data *shell, char *var)
{
	t_env	*new;

	new = ft_new_env(var);
	if (!new)
		return ;
	ft_add_back_env(&shell->env, new);
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
			limit = av[i] - ft_strchr(av[i], '=');
		else
			limit = 0;
		if (limit > 0)
		{
			if (is_valid_key(av[i], limit) == false)
			{
				shell->success_or_failed = 1;
				return (1);
			}
		}
		add_env(shell, av[i]);
		i++;
	}
	shell->success_or_failed = 0;
	return (0);
}
