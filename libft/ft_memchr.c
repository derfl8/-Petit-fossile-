/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:06:57 by abegou            #+#    #+#             */
/*   Updated: 2025/10/22 15:42:26 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*t;

	i = 0;
	t = (const char *)s;
	while (i < n)
	{
		if (t[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
