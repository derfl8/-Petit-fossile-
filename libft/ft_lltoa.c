/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:45 by aldecour          #+#    #+#             */
/*   Updated: 2025/11/06 19:53:48 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_modulo(long long n)
{
	unsigned long long	ull;
	int					i;
	char				*s;
	char				biffur[21];

	i = 19;
	biffur[20] = '\0';
	if (n < 0)
		ull = -n;
	else
		ull = n;
	while (ull)
	{
		biffur[i] = ull % 10 + '0';
		ull /= 10;
		i--;
	}
	if (n < 0)
		biffur[i--] = '-';
	s = ft_strdup(biffur + i + 1);
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_lltoa(long long n)
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
