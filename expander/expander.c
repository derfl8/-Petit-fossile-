/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 16:09:15 by abegou            #+#    #+#             */
/*   Updated: 2026/09/20 21:23:10 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/expander.h"

static void	quote_update(char c, bool *in_s_quote, bool *in_d_quote)
{
	if (c == '\'' && !*in_d_quote)
		*in_s_quote = !*in_s_quote;
	else if (c == '"' && !*in_s_quote)
		*in_d_quote = !*in_d_quote;
}

static int	expand_norm(t_data *shell, char **result, char *str, int i)
{
	if (str[i + 1] == '?')
	{
		*result = join_and_free(*result, ft_itoa(shell->success_or_failed));
		i += 2;
	}
	else if (ft_isalnum(str[i + 1]) || str[i + 1] == '_')
	{
		*result = get_value(shell, *result, str, i + 1);
		i = get_varend(str, i + 1);
	}
	else
	{
		*result = join_and_free(*result, ft_substr(str, i, 1));
		i++;
	}
	return (i);
}

char	*expand_str(t_data *shell, char *str)
{
	char	*result;
	int		i;
	bool	in_s_quote;
	bool	in_d_quote;

	result = ft_strdup("");
	i = 0;
	in_s_quote = false;
	in_d_quote = false;
	while (str[i])
	{
		quote_update(str[i], &in_s_quote, &in_d_quote);
		if (i > 0 && (in_d_quote && result[i -1]))
			result[ft_strlen(result) -1] = '\0';
		if (in_s_quote || str[i] != '$')
		{
			result = join_and_free(result, ft_substr(str, i, 1));
			i++;
		}
		else
			i = expand_norm(shell, &result, str, i);
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
