/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/12 19:09:10 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	parser_init(t_lexer *lexer, const char *line)
{
	lexer->line = line;
	lexer->i = 0;
}

void	parse_logic(t_tree *cmd_current, t_token *next_token, t_lexer *lexer)
{
	int	err_code;

	err_code = 0;
	if (next_token->type == T_WORD)
		parse_cmd(next_token, cmd_current);
	else if (next_token->type == T_REDIR_IN)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_REDIR_OUT)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_APPEND)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_HEREDOC)
		parse_heredoc(next_token, cmd_current, lexer);
	else if (next_token->type == T_PIPE)
		parse_pipe(cmd_current);
}

t_tree	**pf_parser(char *line)
{
	t_tree			**cmd_head;
	t_tree			*cmd_current;
	t_tree			*cmd_cmd;
	t_token			*next_token;
	t_lexer			lexer;

	cmd_cmd = pf_node_new();
	parser_init(&lexer, line);
	cmd_head = NULL;
	while (1)
	{
		next_token = get_next_token(&lexer);
		if (next_token->type == T_EOF)
			break ;
		else if (next_token->type == T_WORD)
			parse_logic(cmd_cmd, next_token, &lexer);
		else
		{
			cmd_current = pf_node_new();
			parse_logic(cmd_current, next_token, &lexer);
			pf_node_add_back(cmd_head, cmd_current);
		}
	}
	return (cmd_head);
}
