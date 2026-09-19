/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:36:48 by abegou            #+#    #+#             */
/*   Updated: 2025/11/05 18:29:32 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]) != 0)
		start++;
	while (ft_strchr(set, s1[end - 1]) != 0 && end > start)
		end--;
	trim = malloc(((end - start) + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + start, (end - start) + 1);
	return (trim);
}
