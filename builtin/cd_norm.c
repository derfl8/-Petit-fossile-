/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 23:05:56 by abegou            #+#    #+#             */
/*   Updated: 2026/06/14 23:17:50 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

void	free_all_pwd(t_data *shell, char *pwd, char *oldpwd, int s_o_f)
{
	shell->success_or_failed = s_o_f;
	if(pwd)
		free(pwd);
	if(oldpwd)
		free(oldpwd);
	return ;
}
