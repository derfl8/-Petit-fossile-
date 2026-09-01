/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 16:06:52 by abegou            #+#    #+#             */
/*   Updated: 2026/09/01 18:35:29 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

static int  redir_in(t_tree *curr)
{
    int fd;

    fd = open(curr->args[0], O_RDONLY);
	if (fd == -1)
	{
		perror(curr->args[0]);
		return (fd);
	}
	dup2(fd, STDIN_FILENO);
    close(fd);
    return (fd);
}

static int  redir_out(t_tree *curr)
{
    int fd;
    
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

static int  append(t_tree *curr)
{
    int fd;

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

void    redirections(t_tree *curr)
{
    t_tree  *next_cmd;
	int	    fd;

    next_cmd = curr->next;
    while (next_cmd && (next_cmd->type == ASL_REDIR_IN || next_cmd->type == ASL_REDIR_OUT || next_cmd->type == ASL_APPEND))
    {
	    if (next_cmd->type == ASL_REDIR_IN)
            fd = redir_in(next_cmd);
	    else if (next_cmd->type == ASL_REDIR_OUT)
            fd = redir_out(next_cmd);
	    else if (next_cmd->type == ASL_APPEND)
            fd = append(next_cmd);
        if (fd == -1)
            exit(1);
        next_cmd = next_cmd ->next;
    }
}
