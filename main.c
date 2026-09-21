/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:15:18 by abegou            #+#    #+#             */
/*   Updated: 2026/09/21 18:48:22 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/builtin.h"
#include "header/expander.h"
#include "header/minishell.h"
#include "libft/libft.h"

void	ft_check_reset_sig_status(t_data *shell)
{
	if (g_signal_status == 2)
		shell->success_or_failed = 130;
	else if (g_signal_status == 3)
		shell->success_or_failed = 131;
}

static char	*get_prompt(void)
{
	if (isatty(0))
		return ("Petit Fossile> ");
	return (NULL);
}

void	post_parse_instructions(t_data *shell, char *line)
{
	t_tree	*tree;

	ft_check_reset_sig_status(shell);
	add_history(line);
	tree = pf_parser(line);
	if (!tree)
		shell->success_or_failed = 2;
	if (tree && heredoc_handler(tree, shell))
	{
		archaic_expand(shell, tree);
		tree_quote_remover(tree);
		ft_exec(shell, tree);
	}
	if (tree)
		free_cmd_tree(tree);
	g_signal_status = 0;
}

int	main_process(t_data *shell)
{
	char	*line;

	while (1)
	{
		line = readline(get_prompt());
		if (!line)
		{
			ft_check_reset_sig_status(shell);
			if (isatty(0))
				ft_putstr_fd("exit\n", 1);
			return (1);
		}
		if (*line)
			post_parse_instructions(shell, line);
		free(line);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	shell;

	(void)ac;
	(void)av;
	rl_outstream = stderr;
	if (!isatty(0))
		rl_prep_term_function = NULL;
	shell.env = init_env(envp);
	shell.success_or_failed = 0;
	signal_init(S_MAIN);
	main_process(&shell);
	ft_free_stack_env(shell.env);
	return (shell.success_or_failed);
}
