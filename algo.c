/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:21:42 by bfrochot          #+#    #+#             */
/*   Updated: 2017/11/09 19:35:23 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	finish(t_lem *l, int sv)
{
	char first;

	if (l->start->dist)
	{
		first = 1;
		while (l->nb > 0)
		{
			--(l->nb);
			if (!first)
				ft_putchar(' ');
			if (first)
				first = 0;
			putmove(ft_itoa(sv - l->nb), l->end->name, l->C);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	exit(0);
}

void	start_move(t_lem *l, char *first)
{
	int		i;
	int		j;
	t_room	*cor;

	j = 0;
	i = -1;
	while ((l->start->links)[++i])
	{
		cor = (l->start->links)[i];
		if (cor->ant == 0 && cor->dist != -1
			&& cor->dist - l->start->dist - l->start->ant < -1)
		{
			--(l->start->ant);
			cor->ant = l->nb - l->start->ant;
			if (!first && !j)
				j = 1;
			else if ((!first && j) || !(*first))
				ft_putchar(' ');
			else if (*first)
				*first = 0;
			putmove(ft_itoa(cor->ant), cor->name, l->C);
		}
	}
}

void	advance(t_room *r, t_lem *l, char *first)
{
	int		i;
	t_room	*cor;

	i = -1;
	if (r == l->start)
		start_move(l, first);
	else
	{
		while (r->ant && (r->links)[++i])
		{
			cor = (r->links)[i];
			if (cor->dist != -1 && cor != l->start
				&& (cor->dist == 0 || (cor->dist < r->dist && cor->ant == 0)))
			{
				cor->ant = cor->dist ? r->ant : ++(cor->ant);
				if (!(*first))
					ft_putchar(' ');
				if (*first)
					*first = 0;
				putmove(ft_itoa(r->ant), cor->name, l->C);
				r->ant = r == l->start ? r->ant - 1 : 0;
			}
		}
	}
}

void	solve(t_lem *l)
{
	int		i;
	char	first;
	t_room	*r;

	i = 0;
	first = 1;
	while (++i <= l->max)
	{
		r = l->rooms;
		while (r)
		{
			// ft_putstr(r->name);
			if (r->dist == i && r->ant)
				advance(r, l, &first);
			r = r->next;
		}
	}
	if (l->start->ant)
		start_move(l, &first);
	ft_putchar('\n');
}

void	aff(t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (r)
	{
		ft_putstr("name = ");
		ft_putstr(r->name);
		ft_putstr(" dist = ");
		ft_putnbr(r->dist);
		ft_putstr("\n");
		r = r->next;
	}
	ft_putstr("max = ");
	ft_putnbr(l->max);
	ft_putstr("\n");
}

void	sort_start(t_lem *l)
{
	int		i;
	char	done;
	t_room	*sv;

	done = 1;
	while (done && !(done = 0))
	{
		i = -1;
		while ((l->start->links)[++i] && (l->start->links)[i + 1])
		{
			if ((l->start->links)[i + 1] > (l->start->links)[i] && (done = 1))
			{
				sv = (l->start->links)[i];
				(l->start->links)[i] = (l->start->links)[i + 1];
				(l->start->links)[i + 1] = sv;
			}
		}
	}
}

void	aff_all(t_room *r)
{
	int i;

	while (r)
	{
		ft_putstr(r->name);
		ft_putstr(" dist = ");
		ft_putnbr(r->dist);
		ft_putstr(" dist2 = ");
		ft_putnbr(r->dist2);
		ft_putstr(" sl = ");
		ft_putnbr(r->sl);
		ft_putchar('\n');
		i = 0;
		while (r->links[i])
		{
			ft_putstr(r->links[i]->name);
			ft_putchar(' ');
			++i;
		}
		ft_putchar('\n');
		r = r->next;
	}
}

void	resol(t_lem *l)
{
	if (!l->start)
		error(13, l);
	if (!l->end)
		error(14, l);
	l->start->ant = l->nb;
	l->end->ant = 0;
	l->end->dist = 0;
	l->start->dist2 = 0;
	set_dist2(l->start, 0, l);
	set_dist(l->end, 0, l);
	// aff_all(l->rooms);
	if (l->start->dist == -1)
		error(12, l);
	if (l->E)
		ft_putchar('\n');
	if (l->C)
		ft_putstr("\033[0m");
	write(1, l->rendu, l->len);
	ft_putchar('\n');
	if (l->start->dist == 1 || l->start->dist == 0)
		finish(l, l->nb);
	short_links(l->rooms);
	// aff_all(l->rooms);
	sort_by_short_links(l, 1, NULL);
	// aff_all(l->rooms);
	sort_start(l);
	// quicksort(l->rooms, l->time, l);
	start_move(l, 0);
	ft_putchar('\n');
	while (l->end->ant != l->nb)
		solve(l);
}
