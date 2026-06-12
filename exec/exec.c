/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:27:46 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 22:33:27 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

static void run_child(t_data *shell, t_tree *tree)
{
	char	*bin;
	char	**env;
	
	bin = path_verif(shell->env, tree->args[0]);
	if (bin == NULL)
	{
		ft_putstr_fd("Petit Fossile: ", 2);
		ft_putstr_fd(tree->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	env = env_to_char(shell);
	execve(bin, tree->args, env);
	perror(tree->args[0]);
	exit(1);
}

void	ft_exec(t_data *shell, t_tree *tree)
{
	int		success;
	pid_t	pid;
	int		status;

	(void)success;
	if (builtin_check(tree->args[0]) == 0)
	{
		success = exec_builtin(shell, tree->args);
		return ;
	}
	pid = fork(); 
	if (pid == 0)
		run_child(shell, tree);
	else if (pid > 0)
		waitpid(pid, &status, 0);
	return ;
}
