/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:09:15 by abegou            #+#    #+#             */
/*   Updated: 2026/09/18 16:04:24 by abegou           ###   ########.fr       */
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

static char	*join_and_free(char *base, char *add)
{
	char	*joined;

	joined = ft_strjoin(base, add);
	if (!joined)
		return (NULL);
	free(base);
	free(add);
	return (joined);
}

static int	get_varend(char *key, int end)
{
	while (key[end] && (ft_isalnum(key[end]) || key[end] == '_'))
		end++;
	return (end);
}

static char	*get_value(t_data *shell, char *result, char *str, int start)
{
	char	*key;
	char	*tmp;
	int		len;

	len = get_varend(str, start) - start;
	key = ft_substr(str, start, len);
	tmp = exp_key_env(shell->env, key);
	free(key);
	if (!tmp)
		tmp = ft_strdup("");
	result = join_and_free(result, tmp);
	return (result);
}

char	*expand_str(t_data *shell, char *str)
{
	char	*result;
	int		i;
	bool	is_quoted;
	char	quote;

	result = ft_strdup("");
	i = 0;
	is_quoted = false;
	quote = '\0';
	while (str[i])
	{
		if (str[i] == '\'' && quote != '"')
			return (NULL);
		if (str[i] == '$' && str[i + 1] == '?')
		{
			result = join_and_free(result, ft_itoa(shell->success_or_failed));
			i += 2;
		}
		else if (str[i] == '$' && (ft_isalnum(str[i + 1]) || str[i + 1] == '_'))
		{
			result = get_value(shell, result, str, i + 1);
			i = get_varend(str, i + 1);
		}
		else
		{
			result = join_and_free(result, ft_substr(str, i, 1));
			i++;
		}
	}
	return (result);
}

void	archaic_expand(t_data *shell, t_tree *tree)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tree)
	{
		i = 0;
		while (tree->args && tree->args[i])
		{
			tmp = ft_strdup(tree->args[i]);
			free(tree->args[i]);
			tree->args[i] = expand_str(shell, tmp);
			free(tmp);
			i++;
		}
		tree = tree->next;
	}
}
