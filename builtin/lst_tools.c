/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:01 by abegou            #+#    #+#             */
/*   Updated: 2026/04/17 18:45:23 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_back_env(t_env **lst, t_env *new)
{
	t_env	*buffer;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
	return ;
}

t_env	*ft_new_env(char *envinfo)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->envinfo = envinfo;
	new_node->next = NULL;
	return (new_node);
}

void	ft_free_stack_env(t_env **array)
{
	t_env	*tmp;

	while (*array)
	{
		tmp = *array;
		(*array) = (*array)->next;
		free(tmp);
	}
	return ;
}
