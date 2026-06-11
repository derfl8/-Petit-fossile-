/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_arg_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 18:12:44 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/27 19:40:10 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static size_t	get_args_nbr(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	free_args(char **args, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static size_t	double_size_realloc(char ***args, size_t size)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = ft_calloc(size + 1, sizeof(char *));
	while ((*args)[i])
	{
		tmp[i] = ft_strdup((*args)[i]);
		if (!tmp[i])
			return (i);
		i++;
	}
	free_args(*args, size / 2);
	*args = tmp;
	return (i - 1);
}

void	realloc_args(char ***args, t_token *current)
{
	static size_t	size;
	size_t			check;

	(void)current;
	if (!*args)
	{
		size = 2;
		*args = ft_calloc(size + 1, sizeof(char *));
	}
	if (!*args)
		return ;
	else if (get_args_nbr(*args) == size)
	{
		size *= 2;
		check = double_size_realloc(args, size);
		if (!(*args)[check])
			return ;
	}
}
