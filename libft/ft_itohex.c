/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:14:24 by aldecour          #+#    #+#             */
/*   Updated: 2025/11/06 19:53:43 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_modulo(int n)
{
	int		i;
	long	l;
	char	*s;
	char	biffur[12];
	char	*hex_base;

	i = 10;
	l = n;
	biffur[11] = '\0';
	hex_base = "0123456789abcdef";
	if (l < 0)
		l = -l;
	while (l)
	{
		biffur[i] = hex_base[l % 16];
		l /= 16;
		i--;
	}
	if (n < 0)
		biffur[i--] = '-';
	s = ft_strdup(biffur + i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_itohex(int n)
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
