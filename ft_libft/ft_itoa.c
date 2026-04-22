/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:52:55 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/24 22:10:34 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_modulo(int n)
{
	int		i;
	long	l;
	char	*s;
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
	s = ft_strdup(biffur + i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == 0)
	{
		s = ft_strdup("0");
		if (!s)
			return (NULL);
		return (s);
	}
	s = ft_modulo(n);
	if (!s)
		return (NULL);
	return (s);
}
