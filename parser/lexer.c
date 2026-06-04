/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:34:16 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/04 16:23:59 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

static bool	is_char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static void	get_quoted_str(t_lexer *lexer)
{
	char	quote;

	quote = lexer->line[lexer->i];
	lexer->i++;
	while (lexer->line[lexer->i] && lexer->line[lexer->i] != quote)
		lexer->i++;
}

static char	*get_token_value(t_lexer *lexer, t_token_type token_type)
{
	size_t	i;
	char	*res;
	int		size;

	i = lexer->i;
	if (token_type <= T_REDIR_OUT)
		lexer->i++;
	else if (token_type <= T_APPEND)
		lexer->i += 2;
	else if (token_type == T_WORD)
	{
		while (lexer->line[lexer->i] && !ft_isspace(lexer->line[lexer->i]))
		{
			if (is_char_in_str(lexer->line[lexer->i], "<>|"))
				break ;
			else if (is_char_in_str(lexer->line[lexer->i], "\"\'"))
				get_quoted_str(lexer);
			else
				lexer->i++;
		}
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
	t_token			*res;
//	t_quote_state	quote;

	if (!lexer->line)
		return (NULL);
	res = malloc(sizeof(t_token));
	while (ft_isspace(lexer->line[lexer->i]))
		lexer->i++;
	if (lexer->line[lexer->i] == '\0')
	{
		res->type = T_EOF;
		res->value = NULL;
		return (res);
	}
	if (!res)
		return (NULL);
	res->type = get_token_type(lexer);
	res->value = get_token_value(lexer, res->type);
	print_token(res);		// DEBUG
	return (res);
}
