/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:58:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/01 17:12:31 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static char	find_em_quotes(t_token token)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = '\0';
	while (token.value[i] && !quote)
	{
		if (token.value[i] == '\'')
			quote = '\'';
		else if (token.value[i] == '\"')
			quote = '\"';
		i++;
	}
	return (quote);
}

bool	is_quote_error(t_token *token)
{
	size_t	i;
	bool	is_quoted;
	char	quote_type;

	is_quoted = false;
	i = 0;
	if (!token || !token->value)
		return (is_quoted);
	quote_type = find_em_quotes(*token);
	while (token->value[i])
	{
		if (token->value[i] == quote_type)
			is_quoted = !is_quoted;
		i++;
	}
	return (is_quoted);
}
