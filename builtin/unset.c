/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:07:59 by abegou            #+#    #+#             */
/*   Updated: 2026/06/01 22:27:04 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

int ft_unset(t_data *shell, char **av)
{
    size_t  nb_arg;
    size_t  i;

    if (!av)
        return (0);
    nb_arg = arg_len(av);
    i = 0;
    while (i++ != nb_arg)
    {
        if (search_env(shell->env, av[i]) == true)
        {
            while (shell->env && ft_strncmp(av[i], shell->env->envinfo, ft_strlen(av[i])) != 0)
		        shell->env = shell->env->next;
            free(shell->env->envinfo);
        }
    }
    return (0);
}
