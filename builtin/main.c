/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:02:48 by abegou            #+#    #+#             */
/*   Updated: 2026/05/06 17:53:18 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

// int	loop(void)
// {
// 	char	*line;

// 	line = readline("->->");
// 	while (1)
// 	{

// 	}
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	t_env	*envinfo;

	envinfo = init_env(envp);
	// ft_env(envinfo, av);
	// ft_pwd(envinfo, av);
	// ft_echo(av);
	ft_exit(envinfo, av, ac);
	return (0);
}
