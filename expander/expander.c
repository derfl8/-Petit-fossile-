/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:09:15 by abegou            #+#    #+#             */
/*   Updated: 2026/09/07 20:53:43 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/expander.h"

char	*exp_value(t_data *shell, t_tree *tree)
{
	int		keysize;
	char	*tmp;

	keysize = ft_strlen(tree->args[0]);
	while (shell->env && ft_strncmp(tree->args[0], shell->env->envinfo, keysize) != 0)
		shell->env = shell->env->next;
	if (shell->env && ft_strncmp(tree->args[0], shell->env->envinfo, keysize) == 0)
	{
		free(shell->env->envinfo);
		tmp = ft_strjoin(tree->args[0], "=");
		if (!tmp)
			return (false);
		shell->env->envinfo = ft_strjoin(tmp, value);
		if (!shell->env->envinfo)
			return (false);
		free(tmp);
	}
	else
		return (false);
	return (true);
}

char	**expand(t_data *shell, t_tree *tree)
{
	char	*exp_str;

	exp_str = exp_value(shell, tree);
	if (exp_str)
	{
		printf("%s\n", exp_str);
		free(exp_str);
	}
	else 
	{
		printf("\n");
		free(exp_str);
	}
}
