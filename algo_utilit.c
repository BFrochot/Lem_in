#include "lem_in.h"

t_room *corres(char *str, t_lem *l)
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

t_room *corres_links(int i, t_lem *l)
{
	t_room *r;
	t_room *s;

	r = l->rooms;
	s = l->time;
	while (r->nam != i && s->nam != i)
	{
		r = r->next;
		s = s->prev;
	}
	return (r->nam == i ? r : s);
}

void	putmove(char *ito, char *str, char C)
{
	char s[ft_strlen(ito) + ft_strlen(str) + C ? 3 + 36 : 3];

	*s = 0;
	if (C)
		ft_strcat(s, "\033[36m");
	ft_strcat(s, "L");
	ft_strcat(s, ito);
	free(ito);
	if (C)
		ft_strcat(s, "\033[0m");
	ft_strcat(s, "-");
	if (C)
		ft_strcat(s, "\033[31m");
	ft_strcat(s, str);
	if (C)
		ft_strcat(s, "\033[0m");
	ft_putstr(s);
	// free(s);
}

void	affi(t_room *r)
{
	ft_putstr("name = ");
	ft_putstr(r->name);
	ft_putstr(" dist = ");
	ft_putnbr(r->dist);
	ft_putstr(" sl = ");
	ft_putnbr(r->sl);
	ft_putstr("\n");
}

void	set_dist2(t_room *r, int i, t_lem *l)
{
	int		c;
	char	done;
	t_room	*s;

	c = -1;
	while ((r->links)[++c])
		corres_links((r->links)[c], l)->dist2 = 1;
	done = c == 0 ? 0 : 1;
	while (done && ++i)
	{
		done = 0;
		r = l->rooms;
		while (r)
		{
			if (r != l->end && r->dist2 == i && (c = -1))
				while ((r->links)[++c])
				{
					s = corres_links((r->links)[c], l);
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
	while ((r->links)[++c])
		corres_links((r->links)[c], l)->dist = 1;
	done = c == 0 ? 0 : 1;
	while (done && ++i)
	{
		done = 0;
		l->max = i;
		r = l->rooms;
		while (r)
		{
			if (r != l->start && r->dist == i && (c = -1))
			{
				while ((r->links)[++c])
				{
					s = corres_links((r->links)[c], l);
					if (s->dist == -1 && s->dist2 < r->dist2 && (done = 1))
					{
						s->dist = i + 1;
						break ;
					}
				}
			}
			r = r->next;
		}
	}
}

void	short_links(t_room *r, t_lem *l)
{
	int i;

	while (r)
	{
		i = -1;
		if (r->dist != -1)
			while ((r->links)[++i])
				if (corres_links((r->links)[i], l)->dist < r->dist)
					++(r->sl);
		r = r->next;
	}
}

void echanger(t_room *a, t_room *b, t_lem *l)
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

void quickSort(t_room *debut, t_room *fin, t_lem *l)
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
	quickSort(save_deb, debut, l);
	quickSort(debut->next, save_fin, l);
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
