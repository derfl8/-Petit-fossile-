/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:06:04 by abegou            #+#    #+#             */
/*   Updated: 2026/06/17 18:24:35 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

int	builtin_check(char *is_builtin)
{
	int	i;

	if (!is_builtin)
		return (1);
	i = ft_strlen(is_builtin);
	if (ft_strncmp(is_builtin, "cd", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "echo", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "env", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "exit", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "export", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "pwd", i) == 0)
		return (0);
	else if (ft_strncmp(is_builtin, "unset", i) == 0)
		return (0);
	else
		return (1);
}

int	exec_builtin(t_data *shell, char **av, t_tree *cmd_tree)
{
	int	i;

	i = ft_strlen(av[0]);
	if (ft_strncmp(av[0], "cd", i) == 0)
		i = ft_cd(shell, av);
	else if (ft_strncmp(av[0], "echo", i) == 0)
		i = ft_echo(shell, av);
	else if (ft_strncmp(av[0], "env", i) == 0)
		i = ft_env(shell, av);
	else if (ft_strncmp(av[0], "exit", i) == 0)
		ft_exit(shell, av, cmd_tree);
	else if (ft_strncmp(av[0], "export", i) == 0)
		i = ft_export(shell, av);
	else if (ft_strncmp(av[0], "pwd", i) == 0)
		i = ft_pwd(shell, av);
	else if (ft_strncmp(av[0], "unset", i) == 0)
		i = ft_unset(shell, av);
	return (i);
}

// static int	how_many_arg(char **arg)
// {
// 	int	i;

// 	i = 0;
// 	while (arg[i])
// 		i++;
// 	return (i);
// }

// char	**arg_exec(char **av)
// {
// 	char	**arg;
// 	int		i;

// 	i = 1;
// 	arg = ft_calloc(sizeof(char *), how_many_arg(av));
// 	while (av[i])
// 	{
// 		arg[i - 1] = ft_strdup(av[i]);
// 		i++;
// 	}
// 	arg[i - 1] = NULL;
// 	return (arg);
// }
