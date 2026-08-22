/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_family.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:42:54 by abegou            #+#    #+#             */
/*   Updated: 2026/08/22 13:50:04 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

void	ft_exec_family(t_data *shell, t_tree *tree, int nb_cmd)
{
    int     **pipe_table;
    t_tree  *current;
    pid_t   *pids;
    int     i;
    int     pid;

    pipe_table = pipes_gen(nb_cmd);
    pids = ft_calloc(sizeof(pid_t), nb_cmd);
    current = tree;
    i = 0;
    while (current)
    {
        if (current->type == ASL_CMD)
        {
			pid = fork();
			if (pid == 0)
    		{
       			if (i > 0)
            		dup2(pipe_table[i - 1][0], STDIN_FILENO);
        		if (i < nb_cmd - 1)
            		dup2(pipe_table[i][1], STDOUT_FILENO);
			}			
			pids[i] = pid;
    		i++;
        }
        current = current->next;
    }
}