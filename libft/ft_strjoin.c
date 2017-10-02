/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:17:18 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/01 16:27:32 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)palloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
