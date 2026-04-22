/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:45:19 by aldecour          #+#    #+#             */
/*   Updated: 2025/11/02 19:19:03 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (size != 0 && nmemb > ((size_t) - 1) / size)
		return (0);
	p = malloc(size * nmemb);
	if (!p)
		return (NULL);
	ft_bzero(p, size * nmemb);
	return (p);
}
