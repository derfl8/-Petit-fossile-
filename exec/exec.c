/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:27:46 by abegou            #+#    #+#             */
/*   Updated: 2026/08/20 19:44:20 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

void	run_child(t_data *shell, t_tree *tree, char **env)
{
	char	*bin;

	bin = path_verif(shell->env, tree->args[0]);
	if (bin == NULL)
	{
		ft_putstr_fd("Petit Fossile: ", 2);
		ft_putstr_fd(tree->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_stack_env(shell->env);
		free_tab(env);
		free_cmd_tree(tree);
		exit(127);
	}
	execve(bin, tree->args, env);
	free(bin);
	free_tab(env);
	perror(tree->args[0]);
	ft_free_stack_env(shell->env);
	free_cmd_tree(tree);
	exit(1);
}

int	cmd_count(t_tree *tree)
{
	int	cmd;

	cmd = 0;
	while (tree)
	{
		if (tree->type == ASL_CMD)
			cmd++;
		tree = tree->next;
	}
	return (cmd);
}

int	**pipes_gen(int nb_cmd)
{
	int	**pipe_table;
	int	i;

	pipe_table = ft_calloc(sizeof(int *), nb_cmd - 1);
	i = 0;
	if (!pipe_table)
		return (NULL);
	while (i < nb_cmd - 1)
	{
		pipe_table[i] = ft_calloc(sizeof(int), 2);
		if (!pipe_table[i] || pipe(pipe_table[i]) == -1)
			return (NULL);
		i++;
	}
	return (pipe_table);
}

static void	ft_exec_alone(t_data *shell, t_tree *tree)
{
	int		success;
	pid_t	pid;
	int		status;
	char	**env;

	(void)success;
	status = 0;
	if (!tree->args)
		return ;
	if (builtin_check(tree->args[0]) == 0)
	{
		success = exec_builtin(shell, tree->args, tree);
		return ;
	}
	env = env_to_char(shell);
	pid = fork();
	if (pid == 0)
		run_child(shell, tree, env);
	else if (pid > 0)
		waitpid(pid, &status, 0);
	free_tab(env);
	shell->success_or_failed = WEXITSTATUS(status);
	return ;
}

void	ft_exec(t_data *shell, t_tree *tree)
{
	int	nb_cmd;

	nb_cmd = cmd_count(tree);
	if (nb_cmd > 1)
		ft_exec_family(shell, tree, nb_cmd);
	else
		ft_exec_alone(shell, tree);
	return ;
}
