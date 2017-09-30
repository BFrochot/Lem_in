/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:35:07 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/30 03:41:45 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new = palloc(len + 1);
	new[len] = 0;
	i = -1;
	while (++i < len && s[start])
	{
		new[i] = s[start];
		++start;
	}
	return (new);
}
