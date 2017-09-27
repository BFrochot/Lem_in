/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:35:07 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/07 14:52:45 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		new[i] = s[start];
		start++;
		i++;
	}
	return (new);
}
