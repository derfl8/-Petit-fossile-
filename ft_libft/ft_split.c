/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 20:38:41 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/23 22:47:30 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_count_words(char const *s, char c)
{
	char	**tab;
	int		i;
	int		count;

	i = 1;
	count = 0;
	if (s[0] == '\0')
	{
		tab = malloc(sizeof (char *));
		return (tab);
	}
	if (s[0] != c)
		count++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	tab = malloc((count + 1) * sizeof (char *));
	return (tab);
}

static int	ft_fill(const char *s, char c, char **tab)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_len = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i + word_len] && s[i + word_len] != c)
				word_len++;
			tab[j] = ft_substr(s, i, word_len);
			if (!tab[j])
				return (0);
			j++;
		}
		i += word_len;
	}
	tab[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = ft_count_words(s, c);
	if (!tab)
		return (NULL);
	if (ft_fill(s, c, tab) == 0)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
		tab = NULL;
	}
	return (tab);
}
