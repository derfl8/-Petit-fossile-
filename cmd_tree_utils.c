/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:04:44 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/07 17:05:33 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.c"

t_tree	*pf_node_new(void)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	node->type = -1;
	node->args = NULL;
	node->next = NULL;
	return (node);
}

t_tree	*pf_node_last(t_tree *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	pf_node_add_back(t_tree **cmd_head, t_tree *new)
{
	t_tree	*last;
	
	if (!cmd_head || !new)
		return ;
	last = pf_node_last(*cmd_head);
	if (!*cmd_head)
		*cmd_head = new;
	else
		last->next = new;
	return ;
}
