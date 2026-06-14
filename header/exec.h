/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:07:05 by abegou            #+#    #+#             */
/*   Updated: 2026/06/14 18:06:58 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"
# include <sys/wait.h>

// exec_builtin.c

char        **arg_exec(char **av);
int         builtin_check(char *is_builtin);
int	exec_builtin(t_data *shell, char **av, t_tree *cmd_tree);

// path.c

char    	*init_path(t_env *tmp, char *cmd);
char	    *path_verif(t_env *env, char *cmd);
char    	**env_to_char(t_data *shell);

// exec.c
void	    ft_exec(t_data *shell, t_tree *tree);

#endif
