/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:00:47 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/12 18:01:17 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	free_cmd_tree(t_tree *cmd_tree)
{
	size_t	i;
	t_tree	*old;

	while (cmd_tree)
	{
		i = 0;
		if (cmd_tree->type != ASL_PIPE)
		{
			while (cmd_tree->args[i])
			{
				free(cmd_tree->args[i]);
				i++;
			}
			free(cmd_tree->args);
		}
		old = cmd_tree;
		cmd_tree = cmd_tree->next;
		free(old);
	}
}
