/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remover.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:58:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/04 15:28:24 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static char	find_em_quotes(t_token token)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = '\0';
	while (token.value[i])
	{
		if (token.value[i] == '\'')
		{
			quote = '\'';
			break ;
		}
		else if (token.value[i] == '\"')
		{
			quote = '\"';
			break ;
		}
		i++;
	}
	return (quote);
}

int	fuck_em_quotes(t_token *token)
{
	size_t	i;
	bool	is_quoted;
	char	quote;
	char	*tmp;

	i = 0;
	is_quoted = false;
	quote = find_em_quotes(*token);
	while (token->value[i])
	{
		if (token->value[i] == quote)
		{
			is_quoted = !is_quoted;
			tmp = token->value + i;
			ft_memmove(tmp, tmp + 1, ft_strlen(tmp));
		}
		i++;
	}
	if (is_quoted)
		return (0);
	return (1);
}
