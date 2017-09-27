/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:59:07 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/07 16:02:16 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*ret;

	ret = dst;
	if (dst < src)
		while (0 < len--)
			*(char *)dst++ = *(char *)src++;
	else
		while (len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
	return (ret);
}
