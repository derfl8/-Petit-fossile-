/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:26:02 by abegou            #+#    #+#             */
/*   Updated: 2026/01/09 20:01:02 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*buffer;

	if (!f || !del || !lst)
		return (NULL);
	map = ft_lstnew(f(lst -> content));
	if (!map)
		return (NULL);
	buffer = map;
	while (lst -> next)
	{
		lst = lst -> next;
		buffer -> next = ft_lstnew(f(lst -> content));
		if (!buffer)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		buffer = buffer -> next;
	}
	return (map);
}
