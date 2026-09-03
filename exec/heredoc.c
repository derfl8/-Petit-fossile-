/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:44:33 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/02 23:09:37 by aldecour         ###   ########.fr       */
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

static void	print_readline_error(int line_nb, char *delim)
{
	ft_putstr_fd("Petit Fossile: warning: ", 2);
	ft_putstr_fd("here-document at line ", 2);
	ft_putstr_fd(ft_itoa(line_nb), 2);
	ft_putstr_fd(" of here-document delimited by end-of-file (wanted '", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
}

//TODO HANDLE VAR EXPANSIONS
static void	heredoc_loop(char *delim, char quote_type, char *file_name)
{
	char	*line;
	int		fd;
	int		line_nb;

	(void)quote_type; //ONLY WHILE ITS NEEDED
	line_nb = 1;
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			print_readline_error(line_nb, delim);
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
		line_nb++;
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
	if (!delim || !*delim)
		return ;
	file_name = get_random_filename(20);
	if (!file_name)
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
		heredoc_loop(delim[i], quote_type, file_name);
		i++;
	}
	free_delimiters(delim);
	free(file_name);
}
