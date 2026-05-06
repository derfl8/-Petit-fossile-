/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/05/06 14:41:48 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static int	handle_exit(char **exit_code)
{
	int	option;
	int	i;
	
	i = 0;
	while (exit_code[i])
	{
		
	}
	if (!ft_isdigit(exit_code[1][0]))
	{
		ft_putstr_fd("Petit Fossile: exit: ", 2);
		ft_putstr_fd(exit_code[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		return (2);
	}
	if (exit_code[2])
	{
		ft_putendl_fd("Petit Fossile: exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

void	ft_exit(t_env *envinfo, char **exit_code)
{
	ft_free_stack_env(envinfo);
	exit(handle_exit(exit_code));
}
