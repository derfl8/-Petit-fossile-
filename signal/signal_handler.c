/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:50:58 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/14 21:27:43 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/signal_handler.h"

void	signal_handler(int sig)
{
	
}

void	signal_init(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
}
