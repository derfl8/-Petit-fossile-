/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 18:52:50 by abegou            #+#    #+#             */
/*   Updated: 2026/04/18 18:55:56 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_size_cut(char *to_cut)
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
	cuted = malloc(sizeof(char) * ft_size_cut(to_cut));
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s3[i] && s3[i] == s4[i] && i < n - 1)
	{
		i++;
	}
	return (s3[i] - s4[i]);
}
