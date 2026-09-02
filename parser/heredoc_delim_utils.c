/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_delim_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 22:36:11 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/01 23:51:19 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool	is_delim_valid(char *delim)
{
	bool	is_quoted;
	int		i;

	i = 0;
	is_quoted = false;
	while (delim[i])
	{
		if (ft_strchr("\'\"", delim[i]))
			is_quoted = !is_quoted;
		i++;
	}
	return (!is_quoted);
}

char	get_delim_quote_type(char *delim)
{
	int	i;

	i = 0;
	while(delim[i])
	{
		if (ft_strchr("\'\"", delim[i]))
			return(delim[i]);
		i++;
	}
	return ('\0');
}

int	find_delim_nbr(t_tree *tree)
{
	int	i;

	i = 0;
	while (tree)
	{
		if (tree->type == ASL_HEREDOC)
			i++;
		tree = tree->next;
	}
	return (i);
}

char	**find_delimiters(t_tree *tree)
{
	char	**delim;
	int		i;
	int		size;

	i = 0;
	size = find_delim_nbr(tree);
	if (!size)
		return (NULL);
	delim = ft_calloc(size + 1, sizeof(char *));
	while (tree)
	{
		if (tree->type == ASL_HEREDOC)
		{
			delim[i] = ft_strdup(tree->args[0]);
			i++;
		}
		tree = tree->next;
	}
	delim[i] = NULL;
	return (delim);
}
