/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 22:04:49 by abegou            #+#    #+#             */
/*   Updated: 2026/09/03 16:07:35 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

bool	is_it_redir(t_tree *tree)
{
	if (tree->next)
	{
		if (tree->next->type == ASL_REDIR_IN
			|| tree->next->type == ASL_REDIR_OUT
			|| tree->next->type == ASL_APPEND)
			return (true);
	}
	return (false);
}

void	exit_bin(t_data *shell, t_tree *tree, char **env)
{
	ft_putstr_fd("Petit Fossile: ", 2);
	ft_putstr_fd(tree->args[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	ft_free_stack_env(shell->env);
	free_tab(env);
	free_cmd_tree(tree);
	exit(127);
}

void	free_int_tab(int **int_tab, int how_many)
{
	int	i;

	i = 0;
	while (i < how_many - 1)
	{
		free(int_tab[i]);
		i++;
	}
	free(int_tab);
	return ;
}
