/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:15:18 by abegou            #+#    #+#             */
/*   Updated: 2026/09/18 17:05:02 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/builtin.h"
#include "header/expander.h"
#include "header/minishell.h"
#include "libft/libft.h"

int	main_process(t_data *shell)
{
	t_tree	*tree;
	char	*line;

	while (1)
	{
		line = readline("Petit Fossile> ");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
			return (1);
		}
		add_history(line);
		tree = pf_parser(line);
		print_tree(tree); //DEBUG LINE
		if (tree)
		{
			if (heredoc_handler(tree, shell))
			{
				archaic_expand(shell, tree);
				tree_quote_remover(tree);
				print_tree(tree); //DEBUG LINE
				ft_exec(shell, tree);
			}
			free_cmd_tree(tree);
		}
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	shell;

	(void)ac;
	(void)av;
	shell.env = init_env(envp);
	shell.success_or_failed = 0;
	shell.is_quoted = false;
	signal_init(S_MAIN);
	main_process(&shell);
	ft_free_stack_env(shell.env);
	return (shell.success_or_failed);
}
