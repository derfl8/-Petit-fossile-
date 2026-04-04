/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/04/04 19:41:09 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	one_char_automaton(t_lexer *lexer, int *token_table, char c)
{
	if (c == '|')
		token_table[T_PIPE]++;
	if (c == '<')
		token_table[T_REDIR_IN]++;
	if (c == '>')
		token_table[T_REDIR_OUT]++;
}

void	two_char_automaton(t_lexer *lexer, int *token_table, char c)
{
	if (c == '<')
		token_table[T_HEREDOC]++;
	if (c == '>')
		token_table[T_APPEND]++;
}

void	token_automaton(t_lexer *lexer, int *token_table, int token_size)
{
	char	c;

	c = lexer->line[lexer->i];
	if (token_size == 0)
	{
		one_char_automaton(lexer, token_table, c);
	}
	if (token_size < 2)
	{
		two_char_automaton(lexer, token_table, c);
	}
	token_table[T_WORD]++;
}

t_token pf_lexer(t_lexer *lexer)
{
	int		i;
	int		token_size;
	int		token_table[T_MAX_TOKENS];
	t_token	res;

	i = 0;
	memset(token_table, '0', T_MAX_TOKENS);
	while (lexer->line[lexer->i] && lexer->line[lexer->i] != ' ')
	{
		token_automaton(lexer, token_table, token_size);
		lexer->i++;
		token_size++;
	}
	return (res);
}

t_tree	pf_parser(char *line)
{
	t_token	next_token;
	t_lexer	lexer;

	lexer.line = line;
	lexer.i = 0;
	next_token = pf_lexer(&lexer);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	pf_parser(av[1]);
}
