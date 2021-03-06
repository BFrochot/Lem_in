/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:48:14 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/03 04:02:29 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	insert_link(t_room *r, t_room *s)
{
	int		i;
	t_room	**new;

	i = 0;
	while (r->links && (r->links)[i])
	{
		if ((r->links)[i] == s)
			return ;
		++i;
	}
	new = palloc(sizeof(t_room *) * (i + 2));
	i = 0;
	while (r->links && (r->links)[i])
	{
		new[i] = (r->links)[i];
		++i;
	}
	new[i] = s;
	new[i + 1] = 0;
	free(r->links);
	r->links = new;
}

void	create_link(char *str1, char *str2, t_lem *lem)
{
	t_room *r;
	t_room *s;

	r = corres(str1, lem);
	if (r == NULL)
		error(7, lem);
	if (r == NULL)
		return ;
	if (!ft_strcmp(str1, str2))
	{
		error(18, lem);
		return ;
	}
	s = corres(str2, lem);
	if (s == NULL)
		error(7, lem);
	if (s == NULL)
		return ;
	if (!lem->error)
	{
		insert_link(s, r);
		insert_link(r, s);
	}
}

void	links2(char *line, t_lem *lem, int i, char *chr)
{
	int j;

	while (chr[i + 1] && chr[i + 1] != ' ')
		++i;
	j = i;
	while (chr[i + 1] && chr[i + 1] == ' ')
		++i;
	if (chr[i + 1])
		error(3, lem);
	else
	{
		i = 0;
		while (chr[i + 1] && chr[i + 1] == ' ')
			++i;
		chr[j + 1] = 0;
		*chr = 0;
		create_link(line, chr + i + 1, lem);
		*chr = '-';
	}
}

void	links(char *line, t_lem *lem, int i)
{
	char	*chr;

	chr = ft_strchr(line, '-');
	if (!chr)
	{
		error(6, lem);
		return ;
	}
	while (chr[i + 1] && chr[i + 1] == ' ')
		++i;
	if (!chr[i + 1])
		error(5, lem);
	else if (ft_strchr(chr + 1, '-'))
		error(4, lem);
	else
		links2(line, lem, i, chr);
}
