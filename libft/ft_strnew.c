/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:01:37 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/01 16:28:04 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new;

	new = (char *)palloc(size + 1);
	if (new == NULL)
		return (NULL);
	while ((size-- + 1))
		new[size + 1] = 0;
	return (new);
}
