/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 22:02:55 by abegou            #+#    #+#             */
/*   Updated: 2026/09/19 22:16:35 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/expander.h"

char	*exp_key_env(t_env *env, char *key_name)
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

char	*join_and_free(char *base, char *add)
{
	char	*joined;

	joined = ft_strjoin(base, add);
	if (!joined)
		return (NULL);
	free(base);
	free(add);
	return (joined);
}

int	get_varend(char *key, int end)
{
	while (key[end] && (ft_isalnum(key[end]) || key[end] == '_'))
		end++;
	return (end);
}

char	*get_value(t_data *shell, char *result, char *str, int start)
{
	char *key;
	char *tmp;
	int len;

	len = get_varend(str, start) - start;
	key = ft_substr(str, start, len);
	tmp = exp_key_env(shell->env, key);
	free(key);
	if (!tmp)
		tmp = ft_strdup("");
	result = join_and_free(result, tmp);
	return (result);
}