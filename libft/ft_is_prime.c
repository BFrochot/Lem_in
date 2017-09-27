/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 07:52:11 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/08 14:42:37 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_prime(int nb)
{
	int max;
	int i;

	if (nb < 2)
		return (0);
	i = 2;
	max = ft_sqrt(nb);
	while (i < max && nb % i != 0)
		i++;
	if (nb % i != 0)
		return (1);
	else
		return (0);
}
