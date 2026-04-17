/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:47:26 by aldecour          #+#    #+#             */
/*   Updated: 2026/04/17 21:16:55 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include <stdbool.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_lexer
{
	const char	*line;
	size_t		i;
}				t_lexer;

typedef enum e_type
{
	T_PIPE,			// |
	T_REDIR_IN,		// <
	T_REDIR_OUT,	// >
	T_HEREDOC,		// <<
	T_APPEND,		// >>
	T_WORD,			// basically anything else
	T_WILDCARD,		// * --MAY NOT BE USED--
	T_MAX_TOKENS,	// keep as last line
}	t_type;

typedef struct s_token
{
	t_type	type;
	char	*value;
}	t_token;

typedef struct s_parser
{
	t_lexer	lexer;
	t_token	next_token;
}			t_parser;

//placeholder command tree
typedef struct s_tree
{
	t_token			token;
	struct s_tree	*left;
	struct s_tree	*right;
}					t_tree;

t_tree	pf_parser(char *line);
#endif
