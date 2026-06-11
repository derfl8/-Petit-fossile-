/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:40:23 by abegou            #+#    #+#             */
/*   Updated: 2025/10/18 14:31:03 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ret;
	const char	*sr;
	size_t		i;

	ret = (char *)dest;
	sr = (const char *)src;
	i = 0;
	while (i < n)
	{
		ret[i] = sr[i];
		i++;
	}
	return (dest);
}
