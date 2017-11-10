/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utilit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:16:10 by bfrochot          #+#    #+#             */
/*   Updated: 2017/11/09 16:24:24 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*corres(char *str, t_lem *l)
{
	t_room *r;
	t_room *s;

	r = l->rooms;
	s = l->time;
	while (r && ft_strcmp(r->name, str))
	{
		r = r->next;
		if (!ft_strcmp(s->name, str))
			return (s);
		s = s->prev;
	}
	return (r);
}

void	putmove(char *ito, char *str, char c)
{
	char s[ft_strlen(ito) + ft_strlen(str) + c ? 3 + 36 : 3];

	*s = 0;
	if (c)
		ft_strcat(s, "\033[36m");
	ft_strcat(s, "L");
	ft_strcat(s, ito);
	free(ito);
	if (c)
		ft_strcat(s, "\033[0m");
	ft_strcat(s, "-");
	if (c)
		ft_strcat(s, "\033[31m");
	ft_strcat(s, str);
	if (c)
		ft_strcat(s, "\033[0m");
	ft_putstr(s);
}

void	set_dist2(t_room *r, int i, t_lem *l)
{
	int		c;
	char	done;
	t_room	*s;

	c = -1;
	while (r->links && (r->links)[++c])
		((r->links)[c])->dist2 = 1;
	done = c == 0 ? 0 : 1;
	while (done && ++i)
	{
		done = 0;
		r = l->rooms;
		while (r)
		{
			if (r != l->end && r->dist2 == i && (c = -1))
				while (r->links && (r->links)[++c])
				{
					s = (r->links)[c];
					if (s->dist2 == -1 && (done = 1))
						s->dist2 = i + 1;
				}
			r = r->next;
		}
	}
}

void	set_dist(t_room *r, int i, t_lem *l)
{
	int		c;
	char	done;
	t_room	*s;

	c = -1;
	while (r->links && (r->links)[++c])
		((r->links)[c])->dist = 1;
	done = c == 0 ? 0 : 1;
	while (done && ++i && (l->max = i))
	{
		done = 0;
		r = l->rooms;
		while (r)
		{
			if (r != l->start && r->dist == i && (c = -1))
			{
				while (r->links && (r->links)[++c])
				{
					s = (r->links)[c];
					if (s->dist == -1 && s->dist2 < r->dist2 && (done = 1))
						s->dist = i + 1;
				}
			}
			r = r->next;
		}
	}
}
