/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:51:56 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/03 02:04:18 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_lem(t_lem *lem)
{
	lem->start = NULL;
	lem->end = NULL;
	lem->rooms = NULL;
	lem->nb = -1;
	lem->E = 0;
	lem->G = 0;
	lem->C = 0;
	lem->fast = 0;
	lem->link = 0;
	lem->line_nb = 1;
	lem->command = 0;
	lem->error = 0;
	lem->max = 0;
	lem->len = 0;
	lem->rendu = NULL;
}

void	short_links(t_room *r)
{
	int		i;
	t_room	*s;

	while (r)
	{
		i = -1;
		if (r->dist != -1)
			while ((r->links)[++i])
			{
				s = (r->links)[i];
				if (s->dist != -1 && s->dist < r->dist)
					++(r->sl);
			}
		r = r->next;
	}
}

void	echanger(t_room *a, t_room *b, t_lem *l)
{
	t_room *sv;
	t_room *sv_prev;

	if (!(a->prev))
		l->rooms = b;
	else
		a->prev->next = b;
	if (a->next)
		a->next->prev = b;
	if (b->next)
		b->next->prev = a;
	if (b->prev)
		b->prev->next = a;
	else
		l->rooms = a;
	sv_prev = b->prev;
	b->prev = a->prev;
	sv = b->next;
	b->next = a->next;
	a->next = sv;
	a->prev = sv_prev;
	if (b == l->time)
		l->time = a;
}

void	quicksort(t_room *debut, t_room *fin, t_lem *l)
{
	t_room	*save_fin;
	t_room	*save_deb;
	t_room	*save;
	int		pivot;

	save_deb = debut;
	save_fin = fin;
	pivot = debut->sl;
	if (!debut || !fin || debut == fin)
		return ;
	while (1)
	{
		while (fin->sl >= pivot && fin != debut)
			fin = fin->prev;
		while (debut->sl < pivot && debut != fin)
			debut = debut->next;
		if (debut == fin)
			break ;
		echanger(debut, fin, l);
		if (fin == save_fin)
			save_fin = debut;
		if (debut == save_deb)
			save_deb = fin;
		save = fin;
		fin = debut;
		debut = save;
	}
	quicksort(save_deb, debut, l);
	quicksort(debut->next, save_fin, l);
}

void	sort_by_short_links(t_lem *l, char done, t_room *prev)
{
	t_room *r;
	t_room *sv;

	r = l->rooms;
	while (r)
		r = r->next;
	while (done && !(done = 0))
	{
		r = l->rooms;
		prev = NULL;
		while (r->next)
		{
			if (r->next->sl < r->sl && (done = 1))
			{
				if (prev)
					prev->next = r->next;
				else
					l->rooms = r->next;
				sv = r->next->next;
				r->next->next = r;
				prev = r->next;
				r->next = sv;
				r = prev;
			}
			prev = r;
			r = r->next;
		}
	}
}
