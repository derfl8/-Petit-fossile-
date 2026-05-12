/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:03:37 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/30 22:25:21 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_modulo(int n, int fd)
{
	int		i;
	long	l;
	char	biffur[12];

	i = 10;
	l = n;
	biffur[11] = '\0';
	if (l < 0)
		l = -l;
	while (l)
	{
		biffur[i] = l % 10 + '0';
		l /= 10;
		i--;
	}
	if (n < 0)
		biffur[i--] = '-';
	ft_putstr_fd(biffur + i + 1, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putstr_fd("0", fd);
	else
		ft_modulo(n, fd);
}
