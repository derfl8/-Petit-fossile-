/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:52:50 by abegou            #+#    #+#             */
/*   Updated: 2026/06/10 18:59:53 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

static size_t	ft_size_cut(char *to_cut)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (to_cut[i])
	{
		if (to_cut[i++] == '=')
		{
			while (to_cut[i])
			{
				i++;
				j++;
			}
		}
	}
	return (j);
}

char	*ft_cut_env(char *to_cut)
{
	char	*cuted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cuted = malloc((sizeof(char) * ft_size_cut(to_cut)) + 1);
	while (to_cut[i])
	{
		if (to_cut[i++] == '=')
		{
			while (to_cut[i])
				cuted[j++] = to_cut[i++];
		}
	}
	cuted[j] = '\0';
	return (cuted);
}

size_t	arg_len(char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*str;
	size_t			i;

	if (size != 0 && nmemb != 0 && (nmemb * size) / size != nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	i = 0;
	while (i < (nmemb * size))
		str[i++] = '\0';
	return (ptr);
}
