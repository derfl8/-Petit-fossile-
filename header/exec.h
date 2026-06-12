/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:07:05 by abegou            #+#    #+#             */
/*   Updated: 2026/06/12 18:35:00 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "minishell.h"

// exec_builtin.c

void	ft_exec(t_data *shell, char **av);

// path.c

char	*path_verif(t_env *env, char *cmd);
char	**env_to_char(t_data *shell);

#endif