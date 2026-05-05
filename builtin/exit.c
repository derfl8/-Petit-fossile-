/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/05/05 16:50:25 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static int	handle_exit(char **exit_code)
{
	// if ()
	// {
	// 	printf("bash: exit: %s: numeric argument required\n", exit_code[1]);
	// 	return (2);
	// }
	if (exit_code[1])
	{
		printf("bash: exit: too many arguments\n");
		return (1);
	}
	return (0);
}

void	ft_exit(t_env *envinfo, char **exit_code)
{
	ft_free_stack_env(envinfo);
	exit(handle_exit(exit_code));
}
