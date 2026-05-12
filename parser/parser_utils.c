/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:35:42 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/12 17:07:33 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	parse_cmd(t_token *current, t_tree *cmd_node)
{
	int		i;
	char	*arg;

	i = 0;
	cmd_node->type = ASL_CMD;
	while (cmd_node->args)
		i++;
	cmd_node->args[i] = current->value;
}

void	parse_redir(t_token *current, t_tree *cmd_node, t_lexer *lexer)
{
	if (current->type == T_REDIR_IN)
		cmd_node->type = ASL_REDIR_IN;
	else if (current->type == T_REDIR_OUT)
		cmd_node->type = ASL_REDIR_OUT;
	else if (current->type == T_APPEND)
		cmd_node->type = ASL_APPEND;
	current = get_next_token(lexer);
	if (current->type != T_WORD)
		return ;
	cmd_node->args[0] = current->value;
}

void	parse_heredoc(t_token *current, t_tree *cmd_node, t_lexer *lexer)
{
	cmd_node->type = ASL_HEREDOC;
	current = get_next_token(lexer);
	if (current->type != T_WORD)
		return ;
	cmd_node->args[0] = current->value;
}

void	parse_pipe(t_tree *cmd_node)
{
	cmd_node->type = ASL_PIPE;
	cmd_node->args = NULL;
}
