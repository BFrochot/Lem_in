/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:14:04 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/05 20:05:36 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*nbr;
	int		size;
	int		oc;
	int		neg;

	neg = n < 0 ? 1 : 0;
	if (n > 0)
		n *= -1;
	oc = n;
	size = 1;
	while ((oc = oc / 10) < 0)
		size++;
	nbr = (char *)malloc(size + neg + 1);
	if (nbr == NULL)
		return (NULL);
	nbr[size + neg] = '\0';
	if (neg == 1)
		nbr[0] = '-';
	while (size-- + neg >= neg + 1)
	{
		nbr[size + neg] = -(n % 10) + '0';
		n = n / 10;
	}
	return (nbr);
}
