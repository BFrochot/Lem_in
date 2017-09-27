/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 14:47:32 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/19 18:09:55 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(long long int value, int power)
{
	if (power == 0)
		return (1);
	while (power > 1)
		value *= value;
	return (value);
}

char	*ft_itoa_base(uintmax_t value, int base, int neg)
{
	long long int	i;
	uintmax_t		save;
	char			*str;
	char			*result;

	i = 0;
	if (value == 0)
		i++;
	save = value;
	while (value > 0 && ++i)
		value = value / base;
	str = "0123456789abcdef";
	result = palloc(i + neg + 1);
	result[i + neg] = '\0';
	result[0] = '-';
	while (i--)
	{
		result[i + neg] = str[save % base];
		save = save / base;
	}
	return (result);
}
