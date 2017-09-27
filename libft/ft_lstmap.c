/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:16:32 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/06 18:45:21 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*sv;
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if ((sv = ft_lstnew(tmp->content, tmp->content_size)))
	{
		elem = sv;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(elem->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			elem = elem->next;
			lst = lst->next;
		}
	}
	return (sv);
}
