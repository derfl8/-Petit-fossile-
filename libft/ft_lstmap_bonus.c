/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldecour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:59:19 by aldecour          #+#    #+#             */
/*   Updated: 2025/10/28 21:07:45 by aldecour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstcpy;
	t_list	*bby_lst;
	void	*cont;

	if (!lst || !del || !f)
		return (NULL);
	lstcpy = NULL;
	while (lst)
	{
		cont = f(lst->content);
		bby_lst = ft_lstnew(cont);
		if (!bby_lst)
		{
			del(cont);
			ft_lstclear(&lstcpy, del);
			break ;
		}
		ft_lstadd_back(&lstcpy, bby_lst);
		lst = lst->next;
	}
	return (lstcpy);
}
