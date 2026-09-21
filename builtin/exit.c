/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:07 by abegou            #+#    #+#             */
/*   Updated: 2026/09/21 19:57:23 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

static bool	wich_case(char *exit_code)
{
	int			i;
	long long	overflow;

	i = 0;
	overflow = 0;
	if (exit_code[0] == '-' || exit_code[0] == '+')
		i++;
	while (exit_code[i])
	{
		if (!ft_isdigit(exit_code[i]))
			return (false);
		if (overflow > LLONG_MAX / 10 || (overflow == LLONG_MAX / 10
				&& (exit_code[i] - '0') > LLONG_MAX % 10))
			return (false);
		overflow = overflow * 10 + (exit_code[i] - '0');
		i++;
	}
	return (true);
}

static void	print_error_arg(char *exit_code)
{
	ft_putstr_fd("Petit Fossile: exit: ", 2);
	ft_putstr_fd(exit_code, 2);
	ft_putendl_fd(": numeric argument required", 2);
}

static void	exit_no_arg(t_data *shell, char **exit_code, t_tree *cmd_tree)
{
	print_error_arg(exit_code[1]);
	ft_free_stack_env(shell->env);
	free_cmd_tree(cmd_tree);
	rl_clear_history();
	exit(2);
}

void	ft_exit(t_data *shell, char **exit_code, t_tree *cmd_tree)
{
	int	how_many;

	how_many = arg_len(exit_code);
	if (how_many > 1 && wich_case(exit_code[1]) == false)
		exit_no_arg(shell, exit_code, cmd_tree);
	else if (how_many > 2)
	{
		ft_putendl_fd("Petit Fossile: exit: too many arguments", 2);
		shell->success_or_failed = 1;
		return ;
	}
	else if (how_many == 2)
	{
		how_many = ((unsigned char)ft_atol(exit_code[1]));
		ft_free_stack_env(shell->env);
		free_cmd_tree(cmd_tree);
		rl_clear_history();
		exit(how_many);
	}
	ft_free_stack_env(shell->env);
	free_cmd_tree(cmd_tree);
	rl_clear_history();
	exit(shell->success_or_failed);
}
