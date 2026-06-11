/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:43:12 by abegou            #+#    #+#             */
/*   Updated: 2025/11/10 20:08:37 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	long	nb;

	nb = n;
	i = ft_len(nb);
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	if (nb < 0)
	{
		ret[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		ret[0] = '0';
	ret[i] = '\0';
	while (nb > 0)
	{
		ret[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ret);
}
