/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:51:17 by abegou            #+#    #+#             */
/*   Updated: 2026/05/27 22:19:53 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

int	ft_pwd(t_data *shell, char **av)
{
	char	buffer[PATH_MAX];
	char	*from_struct;
	t_env	*tmp;

	(void)av;
	tmp = shell->env;
	while (tmp && ft_strncmp("PWD=", tmp->envinfo, 4) != 0)
		tmp = tmp->next;
	if (tmp && ft_strncmp("PWD=", tmp->envinfo, 4) == 0)
	{
		from_struct = ft_cut_env(tmp->envinfo);
		printf("%s\n", from_struct);
		free(from_struct);
		shell->success_or_failed = 0;
		return (0);
	}
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		perror("pwd");
		shell->success_or_failed = 1;
		return (1);
	}
	printf("%s\n", buffer);
	shell->success_or_failed = 0;
	return (0);
}
