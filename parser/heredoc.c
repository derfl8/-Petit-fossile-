/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:44:33 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/02 21:39:05 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	free_delimiters(char **delim)
{
	int	i;

	i = 0;
	while (delim[i])
	{
		free(delim[i]);
		i++;
	}
	free(delim);
}

//TODO HANDLE VAR EXPANSIONS
static void	single_heredoc_loop(char *delim, char quote_type, char *file_name)
{
	char	*line;
	int		fd;

	(void) quote_type; //ONLY WHILE ITS NEEDED
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			//print readline err
			free(line);
			break ;
		}
		if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
			break ;
		//if (quote_type == quote a expand lol mdr)
		//	var expander
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
}

void	store_filename(t_tree *tree, char *file_name)
{
	while (tree)
	{
		if (tree->type == ASL_HEREDOC)
		{
			free(tree->args[0]);
			tree->args[0] = ft_strdup(file_name);
		}
		tree = tree->next;
	}
}

void	heredoc_handler(t_tree *tree)
{
	char	**delim;
	int		i;
	char	quote_type;
	char	*file_name;

	i = 0;
	delim = find_delimiters(tree);
	file_name = get_random_filename(20);
	if (!delim || !*delim || !file_name)
		return ;
	store_filename(tree, file_name);
	while (delim[i])
	{
		if (!is_delim_valid(delim[i]))
		{
			ft_putstr_fd("Petit Fossile : error : Invalid delimiter\n", 2);
			break ;
		}
		quote_type = get_delim_quote_type(delim[i]);
		quote_remover(delim[i]);
		single_heredoc_loop(delim[i], quote_type, file_name);
		i++;
	}
	free_delimiters(delim);
	free(file_name);
}
