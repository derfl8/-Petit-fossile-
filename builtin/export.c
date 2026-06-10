/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 19:40:10 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdlib.h>

static size_t	ft_size_cut(char *to_cut)
{
	size_t	i;

	i = 0;
	while (to_cut[i] != '=' && to_cut[i])
		i++;
	i++;
	return (i);
}

static char	*ft_name_var(char *var)
{
	char	*cut;
	int		i;

	i = 0;
	cut = malloc((sizeof(char) * ft_size_cut(var)) + 1);
	while (var[i] != '=')
	{
		cut[i] = var[i];
		i++;
	}
	cut[i] = '\0';
	return (cut);
}

static int	nb_var(t_data *shell)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = shell->env;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	ft_key_cmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 != '=' && *s2 != '=')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

static void	bubble_sort(char **envtab)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (envtab[i])
	{
		j = i + 1;
		while (envtab[j])
		{
			if (ft_key_cmp(envtab[i], envtab[j]) > 0)
			{
				tmp = envtab[i];
				envtab[i] = envtab[j];
				envtab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

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
