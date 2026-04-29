/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:22:01 by abegou            #+#    #+#             */
/*   Updated: 2026/04/29 19:23:21 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/builtin.h"

void	ft_add_back_env(t_env **lst, t_env *new_node)
{
	t_env	*buffer;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new_node;
	return ;
}

t_env	*ft_new_env(char *envinfo)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->envinfo = ft_strdup(envinfo);
	if (!new_node->envinfo)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	ft_free_stack_env(t_env *array)
{
	t_env	*tmp;

	while (array)
	{
		tmp = array;
		free(tmp->envinfo);
		array = array->next;
		free(tmp);
	}
	return ;
}
