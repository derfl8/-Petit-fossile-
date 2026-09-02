/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:05:56 by abegou            #+#    #+#             */
/*   Updated: 2026/09/02 17:45:51 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

void	cd_pwd_err(t_data *shell)
{
	ft_putendl_fd("Petit Fossile: cd: OLDPWD not set", 2);
	shell->success_or_failed = 1;
}

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
