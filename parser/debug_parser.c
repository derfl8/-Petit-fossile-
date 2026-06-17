/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:03:20 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/16 20:57:05 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"
#include <stdio.h>
void	print_tree(t_tree *cmd_tree)
{
	while (cmd_tree)
	{
		printf("node type : %d\n", cmd_tree->type);
		if (cmd_tree->args)
		{
			for(int i = 0; cmd_tree->args[i]; i++)
				printf("line nb %d : %s\n", i, cmd_tree->args[i]);
		}
		cmd_tree = cmd_tree->next;
		printf("-----------------\n");
	}
}
