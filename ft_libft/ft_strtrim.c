/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:38:23 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/23 22:44:19 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_prefix_trim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_suffix_trim(char const *s1, char const *set, size_t len)
{
	size_t	j;

	while (len > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[len - 1] == set[j])
				break ;
			j++;
		}
		if (j == ft_strlen(set))
			return (len);
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1cpy;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = ft_prefix_trim(s1, set);
	j = ft_suffix_trim(s1, set, ft_strlen(s1));
	s1cpy = ft_substr(s1, i, j - i);
	return (s1cpy);
}
