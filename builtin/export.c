/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:04:01 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 14:00:35 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdlib.h>

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

static void exp_no_arg(t_data *shell)
{
    char	*key;
	char	*value;
    t_env	*tmp;
    
    tmp = shell->env;
    while (tmp)
    {
        key = ft_name_var(tmp->envinfo);
        value = ft_cut_env(tmp->envinfo);
        printf("declare -x %s=", key);
        printf("\"%s\"\n", value);
        free(key);
        free(value);
        tmp = tmp->next;
    }
}    

int	ft_export(t_data *shell, char **av)
{
	if (!av[1])
        exp_no_arg(shell);
	shell->success_or_failed = 0;
	return (0);
}
