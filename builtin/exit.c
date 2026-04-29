/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/04/29 17:59:31 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	ft_exit(t_env *envinfo, int exit_code)
{
	ft_free_stack_env(envinfo);
	exit(exit_code);
}
