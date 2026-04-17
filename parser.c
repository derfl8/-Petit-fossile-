/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/04/17 21:16:56 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	ft_isspace(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (true);
	return (false);
}

char	*get_token_value(t_lexer *lexer, t_type token_type)
{
	size_t	i;
	char	*res;

	i = lexer->i;
	if (token_type <= T_REDIR_OUT)
	{
		lexer->i++;
		return (NULL);
	}
	else if (token_type <= T_APPEND)
	{
		lexer->i += 2;
		return (NULL);
	}
	if (token_type == T_WORD)
	{
		while (!ft_isspace(lexer->line[lexer->i]))
			lexer->i++;
		res = ft_strdup(lexer->i - i);
		return (res);
	}
}

t_type	get_token_type(t_lexer *lexer)
{
	const char	*c;

	c = &lexer->line[lexer->i];
	if (*c == '|' && *c + 1 != '|')
		return (T_PIPE);
	else if (*c == '<' && *c + 1 != '<')
		return (T_REDIR_IN);
	else if (*c == '>' && *c + 1 != '>')
		return (T_REDIR_IN);
	else if (*c == '<' && *c + 1 == '<')
		return (T_HEREDOC);
	else if (*c == '>' && *c + 1 == '>')
		return (T_APPEND);
	return (T_WORD);
}

t_token pf_lexer(t_lexer *lexer)
{
	t_token	res;

	if (!lexer->line)
		return ((t_token) {0});
	while (ft_isspace(lexer->line[lexer->i]))
		lexer->i++;
	res.type = get_token_type(lexer);
	res.value = get_token_value(lexer, res.type);
	return (res);
}

t_tree	pf_parser(char *line)
{
	t_token	next_token;
	t_lexer	lexer;

	lexer.line = line;
	lexer.i = 0;
	next_token = pf_lexer(&lexer);

	return ((t_tree) {0});		//tmp
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	pf_parser(av[1]);
}
