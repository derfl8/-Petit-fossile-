/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:07:05 by abegou            #+#    #+#             */
/*   Updated: 2026/08/31 21:50:30 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <sys/wait.h>

typedef struct s_pipe_ctx
{
	int		**pipe_table;
	pid_t	*pids;
	char	**env;
	int		nb_cmd;
	int		i;
	int		j;
}			t_pipe_ctx;

// exec_builtin.c

char		**arg_exec(char **av);
int			builtin_check(char *is_builtin);
int			exec_builtin(t_data *shell, char **av, t_tree *cmd_tree);

// path.c

char		*init_path(t_env *tmp, char *cmd);
char		*path_verif(t_env *env, char *cmd);
char		**env_to_char(t_data *shell);

// exec.c
void		ft_exec(t_data *shell, t_tree *tree);
int			cmd_count(t_tree *tree);
void		run_child(t_data *shell, t_tree *tree, char **env);
int			**pipes_gen(int nb_cmd);

// exec_family.c
void		ft_exec_pipe(t_data *shell, t_tree *tree, int nb_cmd);
void		free_int_tab(int **int_tab, int how_many);

#endif
