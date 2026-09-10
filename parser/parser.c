/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:10 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/09 21:55:35 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

static void	parse_error(t_parse_error err_type)
{
	if (err_type == ERR_QUOTE)
		ft_putstr_fd("quote error : missing closing quote\n", 2);
	else if (err_type == ERR_MISSING_CMD)
		ft_putstr_fd("command error : missing command\n", 2);
	else if (err_type == ERR_INVALID_TOKEN)
		ft_putstr_fd("synthax error : unexpected token\n", 2);
	else if (err_type == ERR_PIPE)
		ft_putstr_fd("Petit Fossile: synthax error near unexpected token '|'\n", 2);
}

static bool	is_pipe_error(t_tree *tree)
{
	while (tree && tree->type != ASL_PIPE)
	{
		if (tree->type == ASL_CMD && tree->args && tree->args[0])
			return (false);
		tree = tree->next;
	}
	return (true);
}

static bool	is_tree_valid(t_tree *tree)
{
	int		node_pos;
	t_tree	*previous;

	node_pos = 0;
	previous = NULL;
	if (is_pipe_present(tree) && is_pipe_error(tree))
	{
		parse_error(ERR_PIPE);
		return (false);
	}
	return (true);	//tmp
	while (tree)
	{
		previous = tree;
		tree = tree->next;
	}
}

static int	parser_logic(t_tree *cmd_head, t_token *next_token, t_lexer *lexer)
{
	t_tree	*current_cmd;

	current_cmd = get_current_cmd_node(cmd_head);
	if (next_token->type == T_INVALID)
	{
		parse_error(ERR_INVALID_TOKEN);
		return (0);
	}
	if (is_quote_error(next_token))
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

t_tree	*pf_parser(char *line)
{
	t_tree	*cmd_head;
	t_token	*next_token;
	t_lexer	lexer;

	cmd_head = pf_node_new();
	cmd_head->type = ASL_CMD;
	lexer_init(&lexer, line);
	next_token = get_next_token(&lexer);
	while (next_token->type != T_EOF)
	{
		if (parser_logic(cmd_head, next_token, &lexer) == 0)
		{
			free_token(next_token);
			free_cmd_tree(cmd_head);
			return (NULL);
		}
		free_token(next_token);
		next_token = get_next_token(&lexer);
	}
	free_token(next_token);
	if (is_tree_valid(cmd_head))
		return (cmd_head);
	free_cmd_tree(cmd_head);
	return (NULL);
}
