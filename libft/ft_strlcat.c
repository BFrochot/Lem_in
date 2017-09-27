/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:20:40 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/09 16:43:09 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;

	i = 0;
	while (dst[i] && i < size)
		i++;
	dlen = i;
	while (i < size - 1 && size > 0 && src[i - dlen])
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (dlen < size)
		dst[i] = 0;
	return (dlen + ft_strlen(src));
}
