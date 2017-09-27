/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 07:11:41 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/08 14:52:04 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (-1);
	if (power == 0)
		return (1);
	else
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
