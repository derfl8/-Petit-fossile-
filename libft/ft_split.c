/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:28:50 by abegou            #+#    #+#             */
/*   Updated: 2026/03/12 15:17:35 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

static int	ft_word_count(char const *s, char c)
{
	int	wc;
	int	inword;

	wc = 0;
	inword = 0;
	while (*s)
	{
		if (c == *s)
			inword = 0;
		else if (!inword)
		{
			inword = 1;
			wc++;
		}
		s++;
	}
	return (wc);
}

static int	sword(const char *s, char c)
{
	int	end;

	end = 0;
	while (*s)
	{
		if (c == *s)
			return (end);
		s++;
		end++;
	}
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	**array;
	int		end;

	if (s == 0)
		return (NULL);
	word = ft_word_count(s, c);
	array = malloc((word + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	array[word] = NULL;
	while (i < word)
	{
		while (*s == c)
			s++;
		end = sword (s, c);
		array[i] = ft_substr(s, 0, end);
		s += end;
		if (!array[i])
			return (ft_free(array));
		i++;
	}
	return (array);
}
