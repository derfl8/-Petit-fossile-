/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:10:14 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 19:48:37 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

int	main(int ac, char **av, char **envp)
{
	t_data	shell;

	(void)ac;
	(void)av;
	shell.env = init_env(envp);
	ft_export(&shell, av);
	// ft_cd(&shell, av);
	ft_env(&shell, av);
	// ft_pwd(&shell, av);
	// shell.success_or_failed = 0;
	ft_exit(&shell, av, ac);
}
