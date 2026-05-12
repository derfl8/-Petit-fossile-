/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 20:18:23 by aldecour          #+#    #+#             */
/*   Updated: 2026/04/30 20:24:42 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	char	*res;

	res = malloc(sizeof(char) * n);
	if (!res)
		return (NULL);
	ft_strlcpy(res, str, n);
	return (res);
}
