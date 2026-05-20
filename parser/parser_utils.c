/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:35:42 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/20 18:10:49 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/parser.h"

size_t	get_args_nbr(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	free_args(char **args, size_t size)
{
	size_t	i;

	i = 0;
	while (i <= size)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

size_t	double_size_realloc(char ***args, size_t size)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = ft_calloc(size + 1, sizeof(char *));
	while ((*args)[i])
	{
		tmp[i] = ft_strdup((*args)[i]);
		if (!tmp[i])
			return (i);
		i++;
	}
	free_args(*args, size / 2);
	*args = tmp;
	return (i - 1);
}

void	realloc_args(char ***args, t_token *current)
{
	static size_t	size;
	static size_t	i;
	size_t			check;

	if (!*args)
	{
		size = 2;
		*args = ft_calloc(size + 1, sizeof(char *));
	}
	if (!*args)
		return ;
	else if (get_args_nbr(*args) == size)
	{
		size *= 2;
		check = double_size_realloc(args, size);
		if (!(*args)[check])
			return ;
	}
	(*args)[i] = ft_calloc(ft_strlen(current->value) + 1, sizeof(char));
	i++;
}

void	parse_cmd(t_token *current, t_tree *cmd_node)
{
	static size_t	i;

	cmd_node->type = ASL_CMD;
	realloc_args(&cmd_node->args, current);
	cmd_node->args[i] = current->value;
	i++;
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
