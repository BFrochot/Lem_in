/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:33:17 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/05 16:59:54 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int t_f_len;
	int k;
	int sv;

	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	t_f_len = ft_strlen(to_find);
	i = 0;
	while (str[i])
	{
		k = 0;
		sv = i;
		while (str[sv] == to_find[k] && to_find[k] != 0)
		{
			k++;
			sv++;
		}
		if (k == t_f_len)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
