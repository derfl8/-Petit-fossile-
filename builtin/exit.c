/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/05/07 18:17:14 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static bool	wich_case(char *exit_code)
{
	int	i;

	i = 0;
	if (exit_code)
	{
		while (exit_code[i])
		{
			if (!ft_isdigit(exit_code[i]))
				return (false);
			i++;
		}
	}
	return (true);
}

void	ft_exit(t_env *envinfo, char **exit_code, int nb_arg)
{
	if (nb_arg > 1 && wich_case(exit_code[1]) == false)
	{
		ft_putstr_fd("Petit Fossile: exit: ", 2);
		ft_putstr_fd(exit_code[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (nb_arg > 2)
	{
		ft_putendl_fd("Petit Fossile: exit: too many arguments", 2);
		return ;
	}
	ft_free_stack_env(envinfo);
	exit(2);
}
