/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 22:01:45 by abegou            #+#    #+#             */
/*   Updated: 2026/06/11 20:54:25 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	d = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strndup(const char *s, size_t size)
{
	char	*d;
	size_t	i;

	i = 0;
	d = malloc(size * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	while (s[i] || size != i)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}