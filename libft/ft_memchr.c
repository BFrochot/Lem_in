/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:25:55 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/05 18:22:56 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *sv;

	sv = (unsigned char *)s;
	while (n--)
		if (*sv != (unsigned char)c)
			sv++;
		else
			return (sv);
	return (NULL);
}
