/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:58:26 by aldecour          #+#    #+#             */
<<<<<<< HEAD:parser/quote_handling.c
/*   Updated: 2026/09/01 23:58:01 by aldecour         ###   ########.fr       */
=======
/*   Updated: 2026/09/01 17:12:31 by abegou           ###   ########.fr       */
>>>>>>> dev:parser/quote_remover.c
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	tree_quote_remover(t_tree *tree)
{
	size_t	i;

	while (tree)
	{
		i = 0;
		while (tree->args && tree->args[i])
		{
			quote_remover(tree->args[i]);
			i++;
		}
		tree = tree->next;
	}
}

// the quoted str needs to be valid before calling quote_remover
// else the last quote will disappear but all info will be lost about
// any unclosed quote
void	quote_remover(char *str)
{
	size_t	i;
	char	quote;
	bool	is_quoted;

	i = 0;
	is_quoted = false;
	quote = '\0';
	if (!str)
		return ;
	while (str[i])
	{
		if (!is_quoted && ft_strchr("\'\"", str[i]))
			quote = str[i];
		if (quote != '\0' && str[i] == quote)
		{
			is_quoted = !is_quoted;
			ft_memmove(str + i, str + i + 1, ft_strlen(str + i));
		}
		else
			i++;
	}
}

bool	is_quote_error(t_token *token)
{
	size_t	i;
	bool	is_quoted;
	char	quote_type;

	is_quoted = false;
	i = 0;
	quote_type = '\0';
	if (!token || !token->value)
		return (is_quoted);
	while (token->value[i])
	{
		if (!is_quoted && ft_strchr("\'\"", token->value[i]))
			quote_type = token->value[i];
		if (quote_type != '\0' && token->value[i] == quote_type)
			is_quoted = !is_quoted;
		i++;
	}
	return (is_quoted);
}
