/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:59:15 by aldecour          #+#    #+#             */
/*   Updated: 2025/11/08 18:45:32 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_modulo(unsigned long long n)
{
	int					i;
	unsigned long long	l;
	char				*s;
	char				biffur[20];
	char				*hex_base;

	i = 18;
	l = n;
	biffur[19] = '\0';
	hex_base = "0123456789abcdef";
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

char	*ft_ulltohex(unsigned long long n)
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
