/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:41:55 by abegou            #+#    #+#             */
/*   Updated: 2026/04/27 16:57:16 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool	ft_parsecho(char *pars)
{
	int	i;

	i = 0;
	if (pars[i + 1] && pars[i] == '-' && pars[i + 1] == 'n')
	{
		i++;
		while (pars[i])
		{
			if (pars[i] != 'n' && pars[i])
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}

int	ft_echo(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_parsecho(av[i]) == true)
		{
			while (ft_parsecho(av[i]) == true && av[i])
				i++;
			while (av[i])
			{
				printf("%s", av[i]);
				if (av[i + 1])
					printf(" ");
				i++;
			}
		}
		else
		{
			while (av[i])
			{
				printf("%s", av[i]);
				if (av[i + 1])
					printf(" ");
				i++;
			}
			printf("\n");
		}
	}
	return (0);
}
