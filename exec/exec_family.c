/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_family.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:42:54 by abegou            #+#    #+#             */
/*   Updated: 2026/08/22 13:50:04 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

void	ft_exec_family(t_data *shell, t_tree *tree, int nb_cmd)
{
	int		**pipe_table;
	int		exit_code;
	pid_t	*pids;
	t_tree	*current;
	char	**env;
	pid_t	pid;
	int		i;
	int		j;
	int		status;

	pipe_table = pipes_gen(nb_cmd);
	pids = ft_calloc(sizeof(pid_t), nb_cmd);
	env = env_to_char(shell);
	current = tree;
	i = 0;
	while (current)
	{
		if (current->type == ASL_CMD)
		{
			pid = fork();
			if (pid == 0)
			{
				if (i > 0)
					dup2(pipe_table[i - 1][0], STDIN_FILENO);
				if (i < nb_cmd - 1)
					dup2(pipe_table[i][1], STDOUT_FILENO);
				j = 0;
				while (j < nb_cmd - 1)
				{
					close(pipe_table[j][0]);
					close(pipe_table[j][1]);
					j++;
				}
				if (builtin_check(current->args[0]) == 0)
				{
					exit_code = exec_builtin(shell, current->args, current);
					ft_free_stack_env(shell->env);
					free_tab(env);
					free_cmd_tree(tree);
					exit(exit_code);
				}
				else
					run_child(shell, current, env);
			}
			pids[i] = pid;
			i++;
		}
		current = current->next;
	}
	j = 0;
	while (j < nb_cmd - 1)
	{
		close(pipe_table[j][0]);
		close(pipe_table[j][1]);
		j++;
	}
	i = 0;
	while (i < nb_cmd)
	{
		waitpid(pids[i], &status, 0);
		i++;
	}
	shell->success_or_failed = WEXITSTATUS(status);
}
