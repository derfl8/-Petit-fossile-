/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:35:42 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/17 20:33:53 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

void	realloc_args(t_tree *node, char *str)
{
	int		i;

	i = 0;
	if (!node->args)
	{
		node->args = ft_calloc(2, sizeof(char *));
		if (!node->args)
			return ;
		node->args[i] = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	}
	else
	{
		while (node->args[i])
			i++;
		if (node->args[i + 1] == NULL)
			node->args[i] = ft_strdup(str);
	}
}

void	parse_cmd(t_token *current, t_tree *cmd_node)
{
	int		i;

	i = 0;
	cmd_node->type = ASL_CMD;
	realloc_args(cmd_node, current->value);
	while (cmd_node->args[i][0] == '0')
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
