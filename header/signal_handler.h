/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:22:55 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/08 21:07:43 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

#include "minishell.h"
#include <signal.h>

# define S_MAIN 0
# define S_CHILD_HEREDOC 1
# define S_PARENT_HEREDOC 2
# define S_CMD 3

void	signal_handler(int sig);
void	heredoc_signal_handler(int sig);
void	signal_init(int	where_from);
#endif
