/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/05/27 21:35:48 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"
#include <stdlib.h>

// update by cd if PWD unset

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

int	ft_env(t_data *shell, char **av)
{
	size_t	len;
	t_env	*tmp;

	len = arg_len(av);
	tmp = shell->env;
	if (len > 1)
	{
		printf("Too many args for env command\n");
		shell->success_or_failed = 1;
		return (1);
	}
	while (tmp)
	{
		printf("%s\n", tmp->envinfo);
		tmp = tmp->next;
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

bool	update_env(t_env *env, char *key, char *value)
{
	int		keysize;
	char	*tmp;

	keysize = ft_strlen(key);
	while (env && ft_strncmp(key, env->envinfo, keysize) != 0)
		env = env->next;
	if (env && ft_strncmp(key, env->envinfo, keysize) == 0)
	{
		free(env->envinfo);
		tmp = ft_strjoin(key, "=");
		if (!tmp)
			return (false);
		env->envinfo = ft_strjoin(tmp, value);
		if (!env->envinfo)
			return (false);
		free(tmp);
	}
	else
		return (false);
	return (true);
}
