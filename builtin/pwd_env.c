/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:31:14 by abegou            #+#    #+#             */
/*   Updated: 2026/04/18 18:55:37 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_env *envinfo)
{
	char	buffer[PATH_MAX];
	char	*from_struct;

	// update by cd if PWD unset
	while (envinfo != NULL && ft_strncmp("PWD=", envinfo->envinfo, 4) != 0)
		envinfo = envinfo->next;
	if (envinfo != NULL && ft_strncmp("PWD=", envinfo->envinfo, 4) == 0)
	{
		from_struct = ft_cut_env(envinfo->envinfo);
		printf("%s\n", from_struct);
		free(from_struct);
		return (0);
	}
	if (getcwd(buffer, PATH_MAX) == NULL)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", buffer);
	return (0);
}

int	ft_env(t_env *envinfo, char **av)
{
	size_t	len;

	len = arg_len(av);
	if (len > 1)
	{
		printf("Too many args for env command\n");
		return (1);
	}
	while (envinfo != NULL)
	{
		printf("%s\n", envinfo->envinfo);
		envinfo = envinfo->next;
	}
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
			ft_free_stack_env(&envinfo);
			return (NULL);
		}
		ft_add_back_env(&envinfo, new);
	}
	return (envinfo);
}

int	main(int ac, char **av, char **envp)
{
	t_env	*envinfo;

	(void)ac;
	(void)av;
	envinfo = init_env(envp);
	ft_env(envinfo, av);
	ft_pwd(envinfo);
	ft_free_stack_env(&envinfo);
	return (0);
}
