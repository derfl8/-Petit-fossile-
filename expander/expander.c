/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfred <alfred@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:09:15 by abegou            #+#    #+#             */
/*   Updated: 2026/09/11 12:24:44 by alfred           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/expander.h"

static char	*exp_key_env(t_env *env, char *key_name)
{
	int		keysize;
	char	*value;
	
	keysize = ft_strlen(key_name);
	while (env && ft_strncmp(key_name, env->envinfo, keysize) != 0)
		env = env->next;
	if (!env || env->envinfo[keysize] != '=')
		return (NULL);
	value = ft_cut_env(env->envinfo);
	return (value);
}

void	archaic_expand(t_data *shell, t_tree *tree)
{
	int		i;
	char	*exp_str;
	char	*tmp;

	i = 0;
	while (tree)
	{
		while (tree->args && tree->args[i])
		{
			if (ft_strchr(tree->args[i], '$') != NULL)
			{
				tmp = ft_substr(tree->args[i], 0, ft_strchr(tree->args[i], '$') - tree->args[i]);
				printf("tmp = %s\n", tmp);
				if (ft_strncmp(tree->args[i], "$?", 3) == 0)
				{
					exp_str = ft_itoa(shell->success_or_failed);
					free(tree->args[i]);
					tree->args[i] = exp_str;
				}
				else if (ft_strncmp(tree->args[i], "$", 1) == 0)
				{
					tree->args[i] = ft_strtrim(tree->args[i], "$");
					if (exp_key_env(shell->env, tree->args[i]) != NULL)
					{
						exp_str = exp_key_env(shell->env, tree->args[i]);
						free(tree->args[i]);
						tree->args[i] = exp_str;
					}
					else
					{
						free(tree->args[i]);
						tree->args[i] = ft_strdup("");
					}
				}
				tree->args[i] = ft_strjoin(tmp, tree->args[i]);
			}
			i++;
		}
		tree = tree->next;
	}
}
