/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:08:48 by abegou            #+#    #+#             */
/*   Updated: 2026/04/03 17:07:36 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main(void)
{
	const char *prompt = "Petit Fossile :";
	char *res;

	while (1)
	{
		res = readline(prompt);
		if (res)
			add_history(res);
		if (res)
			parser(res);
	}
}
