/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 19:22:00 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/30 22:56:47 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*bby_list;

	bby_list = malloc(sizeof(t_list));
	if (!bby_list)
		return (NULL);
	bby_list->content = content;
	bby_list->next = NULL;
	return (bby_list);
}
