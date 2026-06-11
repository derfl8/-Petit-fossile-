/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/09 22:43:12 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	parse_error(t_parse_error err_type)
{
	if (err_type == ERR_QUOTE)
	{
		
	}
	else if (err_type == ERR_MISSING_CMD)
	{
		
	}
}

void	lexer_init(t_lexer *lexer, const char *line)
{
	lexer->line = line;
	lexer->i = 0;
}

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

int	parser_logic(t_tree *cmd_head, t_token *next_token, t_lexer *lexer)
{
	t_tree	*current_cmd;

	current_cmd = get_current_cmd_node(cmd_head);
	if (!fuck_em_quotes(next_token))
	{
		parse_error(ERR_QUOTE);
		return (0);
	}
	if (next_token->type == T_WORD)
		parse_cmd(next_token, current_cmd);
	else
		parse_special(cmd_head, next_token, lexer);
	return (1);
}

#include <stdio.h>
t_tree	*pf_parser(char *line)
{
	t_tree	*cmd_head;
	t_token	*next_token;
	t_lexer	lexer = {0};

	cmd_head = pf_node_new();
	cmd_head->type = ASL_CMD;
	lexer_init(&lexer, line);
	next_token = get_next_token(&lexer);
	while (next_token->type != T_EOF)
	{
		parser_logic(cmd_head, next_token, &lexer);
		free_token(next_token);
		next_token = get_next_token(&lexer);
	}
	free_token(next_token);
	return (cmd_head);
}
