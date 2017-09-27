/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:49:55 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/05 18:07:39 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *sv;
	char *sv2;

	sv = dst;
	sv2 = (char *)src;
	while (n--)
		*(char *)sv++ = *(const char *)sv2++;
	return (dst);
}
