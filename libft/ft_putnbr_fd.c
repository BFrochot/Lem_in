/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:54:47 by bfrochot          #+#    #+#             */
/*   Updated: 2016/11/07 12:21:24 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n *= -1;
	else
		ft_putchar_fd('-', fd);
	if (n < -9)
		ft_putnbr_fd(-(n / 10), fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}
