/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 22:44:33 by aldecour          #+#    #+#             */
/*   Updated: 2026/09/08 21:49:01 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	quit_conditions(char *line, char *delim, int line_nb)
{
	if (g_signal_status == 2)
		return (1);
	if (!line)
	{
		print_readline_error(line_nb, delim);
		free(line);
		return (1);
	}
	if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

//TODO HANDLE VAR EXPANSIONS
static void	read_heredoc(char *delim, char quote, char *file_name)
{
	char	*line;
	int		fd;
	int		line_nb;

	(void)quote; //ONLY WHILE ITS NEEDED
	line_nb = 1;
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		line = readline("> ");
		if (quit_conditions(line, delim, line_nb))
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

int	child_heredoc(char **delim, char *file_name, t_tree *tree, t_data *shell)
{
	int		i;
	char	quote_type;

	i = 0;
	signal_init(S_CHILD_HEREDOC);
	while (delim[i])
	{
		if (!is_delim_valid(delim[i]))
		{
			ft_putstr_fd("Petit Fossile : error: Invalid delimiter\n", 2);
			break ;
		}
		quote_type = get_delim_quote_type(delim[i]);
		quote_remover(delim[i]);
		g_signal_status = 0;
		read_heredoc(delim[i], quote_type, file_name);
		if (g_signal_status == 2)
			break ;
		i++;
	}
	ft_free_stack_env(shell->env);
	free_cmd_tree(tree);
	free_delimiters(delim);
	free(file_name);
	exit(g_signal_status);
}

void	parent_heredoc(int pid, t_data *shell)
{
	int	status;
	int	wait_ret;

	wait_ret = -1;
	signal_init(S_PARENT_HEREDOC);
	while (wait_ret == -1)
		wait_ret = waitpid(pid, &status, 0);
	signal_init(S_MAIN);
	shell->success_or_failed = WEXITSTATUS(status);
}

int	heredoc_handler(t_tree *tree, t_data *shell)
{
	char	**delim;
	char	*file_name;
	int		pid;

	delim = find_delimiters(tree);
	if (!delim || !*delim)
		return (1);
	file_name = get_random_filename(20);
	if (!file_name)
		return (0);
	store_filename(tree, file_name);
	pid = fork();
	if (pid == 0)
		child_heredoc(delim, file_name, tree, shell);
	else
		parent_heredoc(pid, shell);
	free_delimiters(delim);
	free(file_name);
	if (shell->success_or_failed != 0)
		return (0);
	return (1);
}
