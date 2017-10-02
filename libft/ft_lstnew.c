/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:59:19 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/01 16:26:59 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	elem = (t_list *)palloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = (void *)palloc(content_size);
		if (elem->content == NULL)
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
