/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:22:55 by aldecour          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/06/15 17:52:08 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

#include "minishell.h"
#include <signal.h>

void	signal_handler(int sig);
void	signal_init(void);
#endif
=======
/*   Updated: 2026/06/14 21:16:54 by aldecour         ###   ########.fr       */
=======
/*   Updated: 2026/06/15 17:52:08 by aldecour         ###   ########.fr       */
>>>>>>> 95781fc (implemented signal SIGINT with expected behavior)
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

#include "minishell.h"
#include <signal.h>

<<<<<<< HEAD
>>>>>>> e5cb809 (started working on signals, still very simple prototype)
=======
void	signal_handler(int sig);
void	signal_init(void);
#endif
>>>>>>> 95781fc (implemented signal SIGINT with expected behavior)
