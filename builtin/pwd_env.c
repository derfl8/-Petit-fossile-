/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/14 21:28:48 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

// update by cd if PWD unset

int	ft_pwd(t_data *shell, char **av)
{
	char	buffer[PATH_MAX];
	char	*from_struct;

	(void)av;
	while (shell->env != NULL && ft_strncmp("PWD=",shell->env->envinfo, 4) != 0)
		shell->env = shell->env->next;
	if (shell->env != NULL && ft_strncmp("PWD=", shell->env->envinfo, 4) == 0)
	{
		from_struct = ft_cut_env(shell->env->envinfo);
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

int	ft_env(t_data *shell, char **av)
{
	size_t	len;

	len = arg_len(av);
	if (len > 1)
	{
		printf("Too many args for env command\n");
		shell->success_or_failed = 1;
		return (1);
	}
	while (shell->env != NULL)
	{
		printf("%s\n", shell->env->envinfo);
		shell->env = shell->env->next;
	}
	shell->success_or_failed = 0;
	return (0);
}

t_env	*init_env(char **envp)
{
	t_env	*envinfo;
	t_env	*new;
	int		i;

	envinfo = NULL;
	i = 0;
	while (envp[i])
	{
		new = ft_new_env(envp[i++]);
		if (!new)
		{
			ft_free_stack_env(envinfo);
			return (NULL);
		}
		ft_add_back_env(&envinfo, new);
	}
	return (envinfo);
}
