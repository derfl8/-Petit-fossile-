/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:15:18 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 13:36:16 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minishell.h"

int	main(int ac, char **av, char **envp)
{
    t_data  shell;
    t_tree  *tree;
    char    *line;

    (void)ac;
    (void)av;
    shell.env = init_env(envp);
    shell.success_or_failed = 0;
    while (1)
    {
        line = readline("Petit Fossile> ");
        if (!line)
        {
            ft_putstr_fd("exit\n", 1);
            return (1);
        }
        if (*line)
            add_history(line);
        tree = pf_parser(line);
        if (tree)
        {
            // exp_args(&shell, tree);
            ft_exec(&shell, tree->args);
            // free_tree(tree);
        }
        free(line);
    }
    ft_free_stack_env(shell.env);
    return (shell.success_or_failed);
}
