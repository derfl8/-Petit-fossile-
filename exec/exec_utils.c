/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 22:04:49 by abegou            #+#    #+#             */
/*   Updated: 2026/09/01 22:18:44 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

void    exit_bin(t_data *shell, t_tree *tree, char **env)
{
    ft_putstr_fd("Petit Fossile: ", 2);
	ft_putstr_fd(tree->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_free_stack_env(shell->env);
	free_tab(env);
	free_cmd_tree(tree);
	exit(127);
}
