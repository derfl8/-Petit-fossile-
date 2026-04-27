/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:41:55 by abegou            #+#    #+#             */
/*   Updated: 2026/04/27 17:13:22 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static bool	ft_parsecho(char *pars)
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

static void	echo_n(char **av, int i)
{
	while (av[i] && ft_parsecho(av[i]) == true)
		i++;
	while (av[i])
	{
		printf("%s", av[i]);
		if (av[i + 1])
			printf(" ");
		i++;
	}
}

int	ft_echo(char **av)
{
	int	i;

	i = 1;
	if (av[i] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (ft_parsecho(av[i]) == true)
	{
		echo_n(av, i);
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
	return (0);
}
