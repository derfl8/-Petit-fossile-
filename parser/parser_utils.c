/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:35:42 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/20 21:28:49 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	parse_cmd(t_token *current, t_tree *cmd_node)
{
	static size_t	i;

	if (!cmd_node->args)
		i = 0;
	cmd_node->type = ASL_CMD;
	realloc_args(&cmd_node->args, current);
	cmd_node->args[i] = ft_strdup(current->value);
	i++;
	return ;
}

t_token	*parse_redir(t_token *current, t_tree *cmd_node, t_lexer *lexer)
{
	if (current->type == T_REDIR_IN)
		cmd_node->type = ASL_REDIR_IN;
	else if (current->type == T_REDIR_OUT)
		cmd_node->type = ASL_REDIR_OUT;
	else if (current->type == T_APPEND)
		cmd_node->type = ASL_APPEND;
	current = get_next_token(lexer);
	if (current->type != T_WORD)
	{
		return (current);
	}
	cmd_node->args = calloc(2, sizeof(char *));
	if (!cmd_node->args)
		return (current);
	cmd_node->args[0] = ft_strdup(current->value);
	cmd_node->args[1] = NULL;
	free_token(current);
	return (NULL);
}

t_token	*parse_heredoc(t_token *current, t_tree *cmd_node, t_lexer *lexer)
{
	cmd_node->type = ASL_HEREDOC;
	current = get_next_token(lexer);
	if (current->type != T_WORD)
	{
		return (current);
	}
	cmd_node->args = calloc(2, sizeof(char *));
	cmd_node->args[0] = ft_strdup(current->value);
	cmd_node->args[1] = NULL;
	free_token(current);
	return (NULL);
}

void	parse_pipe(t_tree *cmd_node)
{
	cmd_node->type = ASL_PIPE;
	cmd_node->args = NULL;
}

int	parse_special(t_tree *cmd_head, t_token *next_token, t_lexer *lexer)
{
	t_tree	*cmd_current;
	t_token	*redir_res;

	redir_res = NULL;
	cmd_current = pf_node_new();
	if (next_token->type == T_REDIR_IN)
		parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_REDIR_OUT)
		redir_res = parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_APPEND)
		redir_res = parse_redir(next_token, cmd_current, lexer);
	else if (next_token->type == T_HEREDOC)
		redir_res = parse_heredoc(next_token, cmd_current, lexer);
	else if (next_token->type == T_PIPE)
		parse_pipe(cmd_current);
	pf_node_add_back(cmd_head, cmd_current);
	if (next_token->type == T_PIPE)
	{
		cmd_current = pf_node_new();
		cmd_current->type = ASL_CMD;
		cmd_current->args = NULL;
		pf_node_add_back(cmd_head, cmd_current);
	}
	else if (!redir_res)
		return (1);
	free(redir_res);
	return (0);
}
