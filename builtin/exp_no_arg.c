/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_no_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:29:18 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 19:56:17 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static size_t	ft_size_cut(char *to_cut)
{
	size_t	i;

	i = 0;
	while (to_cut[i] != '=' && to_cut[i])
		i++;
	i++;
	return (i);
}

char	*ft_name_var(char *var)
{
	char	*cut;
	int		i;

	i = 0;
	cut = malloc((sizeof(char) * ft_size_cut(var)) + 1);
	while (var[i] != '=' && var[i])
	{
		cut[i] = var[i];
		i++;
	}
	cut[i] = '\0';
	return (cut);
}

int	nb_var(t_data *shell)
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

void	bubble_sort(char **envtab)
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
