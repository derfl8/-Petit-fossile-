/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 19:54:17 by abegou           ###   ########.fr       */
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

int	ft_export(t_data *shell, char **av)
{
	if (!av[1])
		exp_no_arg(shell);
	shell->success_or_failed = 0;
	return (0);
}
