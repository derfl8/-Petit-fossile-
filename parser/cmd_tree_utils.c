/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:04:44 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/09 22:38:23 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

t_tree	*pf_node_new(void)
{
	t_tree	*node;

	node = malloc(sizeof(t_tree));
	node->type = ASL_NULL;
	node->args = NULL;
	node->next = NULL;
	return (node);
}

t_tree	*get_last_node(t_tree *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	pf_node_add_back(t_tree *cmd_head, t_tree *new)
{
	t_tree	*last;

	if (!cmd_head || !new)
		return ;
	last = get_last_node(cmd_head);
	if (!cmd_head)
		cmd_head = new;
	else
		last->next = new;
	return ;
}

bool	is_pipe_present(t_tree *cmd_head)
{
	if (!cmd_head)
		return (false);
	while (cmd_head)
	{
		if (cmd_head->type == ASL_PIPE)
			return (true);
		cmd_head = cmd_head->next;
	}
	return (false);
}

t_tree	*get_current_cmd_node(t_tree *cmd_head)
{
	t_tree	*current;

	current = NULL;
	while (cmd_head)
	{
		if (cmd_head->type == ASL_CMD)
			current = cmd_head;
		cmd_head = cmd_head->next;
	}
	return (current);
}
