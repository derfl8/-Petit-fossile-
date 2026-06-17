/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 21:27:46 by abegou            #+#    #+#             */
/*   Updated: 2026/06/17 22:12:29 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

 static void    run_child(t_data *shell, t_tree *tree, char **env)
{
	char	*bin;
	char	**exit_code;

	bin = path_verif(shell->env, tree->args[0]);
	if (bin == NULL)
	{
		exit_code = ft_split("127", '\0');
		ft_putstr_fd("Petit Fossile: ", 2);
		ft_putstr_fd(tree->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_exit(shell, exit_code, tree);
	}
	exit_code = ft_split("1", '\0');
	execve(bin, tree->args, env);
	free(env);
	perror(tree->args[0]);
	ft_exit(shell, exit_code, tree);
}

void    ft_exec(t_data *shell, t_tree *tree)
{
    int        success;
    pid_t    pid;
    int        status;
    char    **env;

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
