/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_family.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:42:54 by abegou            #+#    #+#             */
/*   Updated: 2026/09/03 19:32:27 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/exec.h"

static void	builtin_fork(t_data *shell, t_tree *tree, t_tree *curr,
		t_pipe_ctx *ctx)
{
	int	exit_code;

	exit_code = exec_builtin(shell, curr->args, curr);
	ft_free_stack_env(shell->env);
	free_tab(ctx->env);
	free_cmd_tree(tree);
	exit(exit_code);
}

static void	exec_cmd_fork(t_data *shell, t_tree *tree, t_tree *curr,
		t_pipe_ctx *ctx)
{
	ctx->j = 0;
	if (ctx->i > 0)
		dup2(ctx->pipe_table[ctx->i - 1][0], STDIN_FILENO);
	if (ctx->i < ctx->nb_cmd - 1)
		dup2(ctx->pipe_table[ctx->i][1], STDOUT_FILENO);
	while (ctx->j < ctx->nb_cmd - 1)
	{
		close(ctx->pipe_table[ctx->j][0]);
		close(ctx->pipe_table[ctx->j][1]);
		ctx->j++;
	}
	free_int_tab(ctx->pipe_table, ctx->nb_cmd);
	free(ctx->pids);
	if (redirections(curr) == -1)
	{
		ft_free_stack_env(shell->env);
		free_tab(ctx->env);
		free_cmd_tree(tree);
		exit(1);
	}
	if (builtin_check(curr->args[0]) == 0)
		builtin_fork(shell, tree, curr, ctx);
	else
		run_child(shell, curr, ctx->env);
}

static void	close_wait(t_data *shell, t_pipe_ctx *ctx)
{
	int	status;

	ctx->j = 0;
	while (ctx->j < ctx->nb_cmd - 1)
	{
		close(ctx->pipe_table[ctx->j][0]);
		close(ctx->pipe_table[ctx->j][1]);
		ctx->j++;
	}
	free_int_tab(ctx->pipe_table, ctx->nb_cmd);
	ctx->i = 0;
	while (ctx->i < ctx->nb_cmd)
	{
		waitpid(ctx->pids[ctx->i], &status, 0);
		ctx->i++;
	}
	free(ctx->pids);
	free_tab(ctx->env);
	shell->success_or_failed = WEXITSTATUS(status);
}

static void	cmd_fork(t_data *shell, t_tree *tree, t_pipe_ctx ctx, t_tree *curr)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		exec_cmd_fork(shell, tree, curr, &ctx);
	ctx.pids[ctx.i] = pid;
	ctx.i++;
}

void	ft_exec_pipe(t_data *shell, t_tree *tree, int nb_cmd)
{
	t_pipe_ctx	ctx;
	t_tree		*curr;

	ctx.i = 0;
	ctx.j = 0;
	ctx.pipe_table = pipes_gen(nb_cmd);
	if (!ctx.pipe_table)
	{
		shell->success_or_failed = 1;
		perror("Petit Fossile: pipe");
		return ;
	}
	ctx.nb_cmd = nb_cmd;
	ctx.pids = ft_calloc(sizeof(pid_t), nb_cmd);
	ctx.env = env_to_char(shell);
	curr = tree;
	while (curr)
	{
		if (curr->type == ASL_CMD)
			cmd_fork(shell, tree, ctx, curr);
		curr = curr->next;
	}
	close_wait(shell, &ctx);
}
