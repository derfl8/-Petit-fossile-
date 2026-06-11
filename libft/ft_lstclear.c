/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:58:42 by abegou            #+#    #+#             */
/*   Updated: 2026/01/09 19:14:53 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buffer;

	if (!*lst || !lst || !del)
		return ;
	while (*lst)
	{
		buffer = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = buffer;
	}
}
