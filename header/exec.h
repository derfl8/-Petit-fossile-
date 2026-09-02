/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:07:05 by abegou            #+#    #+#             */
/*   Updated: 2026/09/02 22:58:40 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <fcntl.h>
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

// redir.c
int			redirections(t_tree *curr);
void		redir_builtin(t_data *shell, t_tree *tree);

// HEREDOC.C
void	heredoc_handler(t_tree *tree);

//HEREDOC_DELIM_UTILS.C
bool	is_delim_valid(char *delim);
char	get_delim_quote_type(char *delim);
int		find_delim_nbr(t_tree *tree);
char	**find_delimiters(t_tree *tree);

// exec_utils.c
void		free_int_tab(int **int_tab, int how_many);
void		exit_bin(t_data *shell, t_tree *tree, char **env);

#endif
