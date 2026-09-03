/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:06:52 by abegou            #+#    #+#             */
/*   Updated: 2026/09/03 16:07:25 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

void	redir_builtin(t_data *shell, t_tree *tree)
{
	int		dup_stdin;
	int		dup_stdout;
	bool	redir;

	redir = is_it_redir(tree);
	if (redir == true)
	{
		dup_stdin = dup(STDIN_FILENO);
		dup_stdout = dup(STDOUT_FILENO);
	}
	if (redirections(tree) == -1)
		shell->success_or_failed = 1;
	else
		shell->success_or_failed = exec_builtin(shell, tree->args, tree);
	if (redir == true)
	{
		dup2(dup_stdin, STDIN_FILENO);
		dup2(dup_stdout, STDOUT_FILENO);
		close(dup_stdin);
		close(dup_stdout);
	}
}

static int	redir_in(t_tree *curr)
{
	int	fd;

	fd = open(curr->args[0], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Petit Fossile: ", 2);
		perror(curr->args[0]);
		return (fd);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (fd);
}

static int	redir_out(t_tree *curr)
{
	int	fd;

	fd = open(curr->args[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(curr->args[0]);
		return (fd);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (fd);
}

static int	append(t_tree *curr)
{
	int	fd;

	fd = open(curr->args[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror(curr->args[0]);
		return (fd);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (fd);
}

int	redirections(t_tree *curr)
{
	t_tree	*next_cmd;
	int		fd;

	fd = -1;
	next_cmd = curr->next;
	while (next_cmd && (next_cmd->type == ASL_REDIR_IN
			|| next_cmd->type == ASL_REDIR_OUT || next_cmd->type == ASL_APPEND
			|| next_cmd->type == ASL_HEREDOC) && next_cmd->args)
	{
		if (next_cmd->type == ASL_REDIR_IN || next_cmd->type == ASL_HEREDOC)
			fd = redir_in(next_cmd);
		else if (next_cmd->type == ASL_REDIR_OUT)
			fd = redir_out(next_cmd);
		else if (next_cmd->type == ASL_APPEND)
			fd = append(next_cmd);
		if (fd == -1)
			return (fd);
		next_cmd = next_cmd->next;
	}
	return (0);
}
