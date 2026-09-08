/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 22:46:27 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/07 22:49:20 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	free_delimiters(char **delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		free(delim[i]);
		i++;
	}
	free(delim);
}

void	print_readline_error(int line_nb, char *delim)
{
	char	*nb_tmp;

	nb_tmp = ft_itoa(line_nb);
	ft_putstr_fd("Petit Fossile: warning: ", 2);
	ft_putstr_fd("here-document at line ", 2);
	ft_putstr_fd(nb_tmp, 2);
	ft_putstr_fd(" of here-document delimited by end-of-file (wanted '", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
	free(nb_tmp);
}

void	store_filename(t_tree *tree, char *file_name)
{
	while (tree)
	{
		if (tree->type == ASL_HEREDOC)
		{
			free(tree->args[0]);
			tree->args[0] = ft_strdup(file_name);
		}
		tree = tree->next;
	}
}
