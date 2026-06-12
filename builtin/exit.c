/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 13:20:34 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static bool	wich_case(char *exit_code)
{
	int	i;

	i = 0;
	if (exit_code)
	{
		if (exit_code[0] == '-')
			i++;
		while (exit_code[i])
		{
			if (!ft_isdigit(exit_code[i]))
				return (false);
			i++;
		}
	}
	return (true);
}

void	ft_exit(t_data *shell, char **exit_code)
{
	int	how_many;

	how_many = arg_len(exit_code);
	if (how_many > 1 && wich_case(exit_code[1]) == false)
	{
		ft_putstr_fd("Petit Fossile: exit: ", 2);
		ft_putstr_fd(exit_code[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (how_many > 2)
	{
		ft_putendl_fd("Petit Fossile: exit: too many arguments", 2);
		return ;
	}
	else if (how_many == 2)
	{
		ft_free_stack_env(shell->env);
		exit(((unsigned char)ft_atol(exit_code[1])));
	}
	ft_free_stack_env(shell->env);
	exit(shell->success_or_failed);
}
