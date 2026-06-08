/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/08 20:18:28 by aldecour         ###   ########.fr       */
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

void	parse_special(t_tree *cmd_head, t_token *next_token, t_lexer *lexer)
{
	t_tree	*cmd_current;

	cmd_current = pf_node_new();
	if (next_token->type == T_REDIR_IN)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_REDIR_OUT)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_APPEND)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_HEREDOC)
		parse_heredoc(next_token, cmd_current, lexer);
	else if (next_token->type == T_PIPE)
		parse_pipe(cmd_current);
	pf_node_add_back(cmd_head, cmd_current);
}
#include <stdio.h>
t_tree	*pf_parser(char *line)
{
	t_tree	*cmd_head;
	t_token	*next_token;
	t_lexer	lexer = {0};

	cmd_head = pf_node_new();
	lexer_init(&lexer, line);
	next_token = get_next_token(&lexer);
	while (next_token->type != T_EOF)
	{
		if (!fuck_em_quotes(next_token))
		{
			parse_error(ERR_QUOTE);
			return (NULL);
		}
		if (next_token->type == T_WORD)
			parse_cmd(next_token, cmd_head);
		else
			parse_special(cmd_head, next_token, &lexer);
		free_token(next_token);
		next_token = get_next_token(&lexer);
	}
	free_token(next_token);
	return (cmd_head);
}
