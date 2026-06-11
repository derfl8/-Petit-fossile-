/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/06/11 18:21:14 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct s_lexer
{
	const char	*line;
	size_t		i;
}				t_lexer;

typedef enum e_token_type
{
	T_PIPE,			// |
	T_REDIR_IN,		// <
	T_REDIR_OUT,	// >
	T_HEREDOC,		// <<
	T_APPEND,		// >>
	T_WORD,
	T_EOF,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

typedef enum e_asl_type
{
	ASL_NULL,
	ASL_PIPE,
	ASL_REDIR_IN,
	ASL_REDIR_OUT,
	ASL_HEREDOC,
	ASL_APPEND,
	ASL_CMD,
}	t_asl_type;

typedef struct s_tree
{
	t_asl_type		type;
	char			**args;
	struct s_tree	*next;
}					t_tree;

typedef	enum	e_parse_error
{
	ERR_QUOTE,
	ERR_MISSING_CMD,
}	t_parse_error;

// FUNCTIONS
t_token *get_next_token(t_lexer *lexer);
t_tree	*pf_parser(char *line);
void	free_token(t_token *token);

// CMD_TREE_UTILS.C
t_tree	*pf_node_new(void);
t_tree	*get_last_node(t_tree *node);
void	pf_node_add_back(t_tree *cmd_head, t_tree *new);
bool	is_pipe_present(t_tree *cmd_head);
t_tree	*get_current_cmd_node(t_tree *cmd_head);

// PARSER_UTILS.C
void	parse_cmd(t_token *current, t_tree *cmd_node);
void	parse_special(t_tree *cmd_head, t_token *next_token, t_lexer *lexer);
void	parse_redir(t_token *current, t_tree *cmd_node, t_lexer *lexer);
void	parse_heredoc(t_token *current, t_tree *cmd_node, t_lexer *lexer);
void	parse_pipe(t_tree *cmd_node);

// DYNAMIC_ARG_TABLE.C
void	realloc_args(char ***args, t_token *current);
void	free_args(char **args, size_t size);

// QUOTE_REMOVER.C
bool	is_quote_error(t_token *token);
#endif
