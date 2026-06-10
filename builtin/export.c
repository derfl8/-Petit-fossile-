/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 13:33:12 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static size_t	ft_size_cut(char *to_cut)
{
	size_t	i;

	i = 0;
	while (to_cut[i] != '=')
		i++;
	i++;
	return (i);
}

static char	*ft_name_var(char *var)
{
	char	*cut;
    int     i;

    i = 0;
	cut = malloc((sizeof(char) * ft_size_cut(var)) + 1);
	while (var[i - 1] != '=')
	{
		cut[i] = var[i];
        i++;
	}
	cut[i] = '\0';
	return (cut);
}

int	ft_export(t_data *shell, char **av)
{
	t_env	*tmp;

	tmp = shell->env;
	if (!av[1])
	{
		while (tmp)
		{
			printf("declare -x %s", ft_name_var(tmp->envinfo));
			printf("\"%s\"\n", ft_cut_env(tmp->envinfo));
			tmp = tmp->next;
		}
	}
	shell->success_or_failed = 0;
	return (0);
}
