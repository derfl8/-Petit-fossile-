/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/05/12 12:38:33 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>
#include <stdlib.h>
#include <libft.h>

# define LEFT 1
# define RIGHT 2

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
	T_WORD,			// basically anything else
	T_EOF,
	T_MAX_TOKENS,	// keep as last line
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
}					t_token;

typedef enum e_asl_type
{
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

// FUNCTIONS
t_token *get_next_token(t_lexer *lexer);

t_tree	**pf_parser(char *line);

// CMD_TREE_UTILS.C
t_tree	*pf_node_new(void);
t_tree	*pf_node_last(t_tree *node);
void	pf_node_add_back(t_tree **cmd_head, t_tree *new);

// PARSER_UTILS.C
void	parse_cmd(t_token *current, t_tree *cmd_node);
void	parse_redir(t_token *current, t_tree *cmd_node, t_lexer *lexer);
void	parse_heredoc(t_token *current, t_tree *cmd_node, t_lexer *lexer);
#endif
