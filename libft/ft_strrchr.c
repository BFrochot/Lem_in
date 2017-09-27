/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 23:43:30 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/04 23:48:48 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	if (c == 0)
		return ((char *)s + len);
	else
	{
		while (s[len] != (char)c && len >= 0)
			len--;
		if (len == -1)
			return (NULL);
		else
			return ((char *)s + len);
	}
}
