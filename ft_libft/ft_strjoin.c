/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:36:52 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/29 20:40:44 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*scat;
	int		s1len;
	int		s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	scat = malloc(sizeof (char) *(s1len + s2len + 1));
	if (!scat)
		return (NULL);
	ft_strlcpy(scat, s1, s1len + 1);
	ft_strlcpy(scat + s1len, s2, s2len + 1);
	return (scat);
}
