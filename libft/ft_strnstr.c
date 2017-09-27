/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:39:00 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/06 14:53:10 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		lit_len;
	int		k;
	size_t	sv;

	lit_len = ft_strlen(little);
	if (lit_len == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		k = 0;
		sv = i;
		while (big[sv] == little[k] && little[k] != 0 && sv < len)
		{
			k++;
			sv++;
		}
		if (k == lit_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
