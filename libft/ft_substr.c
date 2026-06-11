/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:07:53 by abegou            #+#    #+#             */
/*   Updated: 2025/11/25 18:25:56 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
