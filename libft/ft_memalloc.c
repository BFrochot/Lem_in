/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:52:54 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/01 16:27:09 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *new;

	new = (void *)palloc(size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
