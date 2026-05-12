/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/12 13:10:11 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parser_init(t_lexer *lexer, t_token_type *old_type, const char *line)
{
	lexer->line = line;
	lexer->i = 0;
	*old_type = (t_token_type)-1;
}

void	parse_logic(t_tree *cmd_current, t_token *next_token, t_lexer *lexer)
{
	int	err_code;
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
		parse_pipe(next_token, cmd_current, lexer);
}

t_tree	**pf_parser(char *line)
{
	t_tree			**cmd_head;
	t_tree			*cmd_current;
	t_token			*next_token;
	t_token_type	old_type;
	t_lexer			lexer;

	parser_init(&lexer, &old_type, line);
	cmd_current = pf_node_new();
	while (1)	
	{
		if (next_token)
			old_type = next_token->type;
		next_token = get_next_token(&lexer);
		if (next_token->type == T_EOF)
			break ;
		else if (old_type != -1 && next_token->type != old_type)
		{
			pf_node_add_back(cmd_head, cmd_current);
			cmd_current = pf_node_new();
		}
		else
			parse_logic(cmd_current, next_token, &lexer);
	}
	return (cmd_head);
}
