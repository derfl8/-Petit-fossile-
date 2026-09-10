/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:50:58 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/08 21:14:03 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/signal_handler.h"

volatile sig_atomic_t	g_signal_status = 0;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_status = sig;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	child_heredoc_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_status = sig;
		write(1, "\n", 1);
		close(0);
	}
}

void	parent_heredoc_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_status = sig;
	}
}

void	cmd_signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_signal_status = sig;
		write(1, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		g_signal_status = sig;
		write(1, "Quit\n", 5);
	}
}

void	signal_init(int where_from)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (where_from == S_MAIN)
	{
		sa.sa_handler = signal_handler;
		signal(SIGQUIT, SIG_IGN);
	}
	else if (where_from == S_CHILD_HEREDOC)
	{
		sa.sa_handler = child_heredoc_signal_handler;
		signal(SIGQUIT, SIG_IGN);
	}
	else if (where_from == S_PARENT_HEREDOC)
	{
		sa.sa_handler = parent_heredoc_signal_handler;
		signal(SIGQUIT, SIG_IGN);
	}
	else if (where_from == S_CMD)
	{
		sa.sa_handler = cmd_signal_handler;
		sigaction(SIGQUIT, &sa, NULL);
	}
	sigaction(SIGINT, &sa, NULL);
}
