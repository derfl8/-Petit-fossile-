/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:50:58 by aldecour          #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2026/06/16 20:39:51 by aldecour         ###   ########.fr       */
=======
/*   Updated: 2026/06/14 21:27:43 by aldecour         ###   ########.fr       */
>>>>>>> e5cb809 (started working on signals, still very simple prototype)
=======
/*   Updated: 2026/06/15 21:40:10 by aldecour         ###   ########.fr       */
>>>>>>> 95781fc (implemented signal SIGINT with expected behavior)
/*                                                                            */
/* ************************************************************************** */

#include "../header/signal_handler.h"

<<<<<<< HEAD
<<<<<<< HEAD
volatile int g_signal_status = 0;

void	signal_handler(int sig)
{
	g_signal_status = sig;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
=======
void	signal_handler(int sig)
{
	
>>>>>>> e5cb809 (started working on signals, still very simple prototype)
=======
volatile int g_signal_status = 0;

void	signal_handler(int sig)
{
	g_signal_status = sig;
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
>>>>>>> 95781fc (implemented signal SIGINT with expected behavior)
}

void	signal_init(void)
{
	struct sigaction sa;

<<<<<<< HEAD
<<<<<<< HEAD
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
=======
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
>>>>>>> e5cb809 (started working on signals, still very simple prototype)
=======
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
>>>>>>> 95781fc (implemented signal SIGINT with expected behavior)
}
