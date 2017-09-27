/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:25:08 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/07 13:53:47 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] == s2[i] && n-- && s1[i] && s2[i])
		i++;
	if (n == 0)
	{
		if (s1[i - 1] == s2[i - 1])
			return (1);
	}
	else if (s1[i] == s2[i])
		return (1);
	return (0);
}
