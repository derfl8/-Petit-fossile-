/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:44:33 by aldecour          #+#    #+#             */
/*   Updated: 2026/07/14 15:12:57 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

bool	is_delim_valid(char *delim)
{
	bool	is_quoted;
	int		i;

	i = 0;
	is_quoted = false;
	while (delim[i])
	{
		if (ft_strchr("\'\"", delim[i]))
			is_quoted = !is_quoted;
		i++;
	}
	return (!is_quoted);
}

char	get_delim_quote_type(char *delim);
{
	int	i;

	i = 0;
	while(delim[i])
	{
		if (ft_strchr("\'\"", delim[i]))
			return(delim[i]);
		i++;
	}
	return ('\0');
}

//TODO : make it so that it finds EVERY delim for all the heredocs
char	*find_delimiter(t_tree *tree)
{
	while (tree && tree->type != ASL_HEREDOC)
		tree = tree->next;
	if (!tree || tree->type != ASL_HEREDOC)
		return (NULL);
	return (tree->args[0]);
}

void	single_heredoc_loop(char *delim)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			//print readline err
			free(line);
			break;
		}
		if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
			break ;
		//var expander
		//store_current_line();
		free(line);
	}
}

void	heredoc_handler(t_tree *tree)
{
	char	**delim;
	int	i;

	line = NULL;
	delim = find_delimiter(tree);
	if (!delim || !is_delim_valid(delim))
		return ;			//TODO : handle errors (print err message before returning)
	quote_remover(delim);
	while (delim[i])
	{
		single_heredoc_loop(delim[i]);
		i++;
	}
}
