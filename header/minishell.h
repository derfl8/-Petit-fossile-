/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:58:55 by abegou            #+#    #+#             */
/*   Updated: 2026/09/02 21:24:55 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "builtin.h"
# include "exec.h"
# include "parser.h"
# include "signal_handler.h"

# include <sys/stat.h>
# include <fcntl.h>

extern volatile int g_signal_status;

#endif
