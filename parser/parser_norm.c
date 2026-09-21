/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_norm_CASSELESCOUILLES.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 22:51:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/20 22:53:21 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	pipe_moment(t_tree *cmd_current, t_tree *cmd_head)
{
	cmd_current = pf_node_new();
	cmd_current->type = ASL_CMD;
	cmd_current->args = NULL;
	pf_node_add_back(cmd_head, cmd_current);
}
