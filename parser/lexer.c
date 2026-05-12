/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:34:16 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/12 13:32:59 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static char	*get_token_value(t_lexer *lexer, t_token_type token_type)
{
	size_t	i;
	char	*res;
	int		size;

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
		while (lexer->line[lexer->i] && !ft_isspace(lexer->line[lexer->i]))
			lexer->i++;
		size = lexer->i - i + 1;
		res = ft_strndup(&lexer->line[i], size);
		return (res);
	}
	return (NULL);
}

static t_token_type	get_token_type(t_lexer *lexer)
{
	const char	*c;

	c = &lexer->line[lexer->i];
	if (c[0] == '\0')
		return (T_EOF);
	else if (c[0] == '|' && c[1] != '|')
		return (T_PIPE);
	else if (c[0] == '<' && c[1] != '<')
		return (T_REDIR_IN);
	else if (c[0] == '>' && c[1] != '>')
		return (T_REDIR_OUT);
	else if (c[0] == '<' && c[1] == '<')
		return (T_HEREDOC);
	else if (c[0] == '>' && c[1] == '>')
		return (T_APPEND);
	return (T_WORD);
}

#include <stdio.h>

static void	print_token(t_token *token)
{
	printf("token type : %d\n", token->type);
	printf("token value : %s\n", token->value);
	printf("--------------------\n");
}

t_token	*get_next_token(t_lexer *lexer)
{
	t_token	*res;

	if (!lexer->line)
		return (&(t_token){-1});
	while (ft_isspace(lexer->line[lexer->i]))
		lexer->i++;
	if (lexer->line[lexer->i] == '\0')
		return (&(t_token){.type = T_EOF, .value = NULL});
	res = malloc(sizeof(t_token));
	if (!res)
		return (NULL);
	res->type = get_token_type(lexer);
	res->value = get_token_value(lexer, res->type);
	print_token(res);
	return (res);
}
