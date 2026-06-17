/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:05:56 by abegou            #+#    #+#             */
/*   Updated: 2026/06/15 15:59:55 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

int	free_all_pwd(t_data *shell, char *pwd, char *oldpwd, int s_o_f)
{
	shell->success_or_failed = s_o_f;
	if (pwd)
		free(pwd);
	if (oldpwd)
		free(oldpwd);
	return (s_o_f);
}

int	pre_cd(t_data *shell, char *pwd, char *oldpwd, char *av)
{
	getcwd(oldpwd, PATH_MAX);
	if (path_check(shell, av, pwd, oldpwd) == false)
		return (1);
	getcwd(pwd, PATH_MAX);
	update_env(shell->env, "PWD", pwd);
	oldpwd_update(shell, oldpwd);
	return (0);
}
