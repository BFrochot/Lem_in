#include "lem_in.h"

t_room *corres(char *str, t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (r && ft_strcmp(r->name, str))
		r = r->next;
	return (r);
}

t_room *corres_links(int i, t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (r && r->nam != i)
		r = r->next;
	return (r);
}

void	putmove(int i, char *str, char C)
{
	char *s;
	char *ito;

	ito = ft_itoa(i);
	s = malloc(ft_strlen(ito) + ft_strlen(str) + C ? 3 + 36 : 3);
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
	free(s);
}

void	affi(t_room *r)
{
	ft_putstr("name = ");
	ft_putstr(r->name);
	ft_putstr(" dist = ");
	ft_putnbr(r->dist);
	ft_putstr(" nam = ");
	ft_putnbr(r->nam);
	ft_putstr("\n");
}

// void	set_dist(t_room *r, int i, t_lem *l)
// {
// 	int c;
// 	t_room *s;

// 	// affi(r);
// 	if (l->max < r->dist)
// 		l->max = r->dist;
// 	if (r == l->start)
// 		return ;
// 	c = -1;
// 	while ((r->links)[++c])
// 	{
// 		s = corres_links((r->links)[c], l);
// 		if (s->dist == -1 || s->dist > i + 1)
// 		{
// 			s->dist = i + 1;
// 			set_dist(s, i + 1, l);
// 		}
// 	}
// }

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
				while ((r->links)[++c])
				{
					s = corres_links((r->links)[c], l);
					if (s->dist == -1 && (done = 1))
						s->dist = i + 1;
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
				if (corres_links((r->links)[i], l)->dist == r->dist - 1)
					++(r->sl);
		r = r->next;
	}
}

void echanger(t_room *ap, t_room *a, t_room *b, t_room *bp, t_lem *l)
{
	t_room *sv;
	t_room *sv_prev;

	if (!(ap))
		l->rooms = b;
	else
		ap->next = b;
	sv_prev = b->prev;
	b->prev = ap;
	sv = b->next;
	b->next = a->next;
	bp->next = a;
	a->next = sv;
	a->prev = sv_prev;
}

void quickSort(t_room *debut, t_room *fin, t_lem *l)
{
    t_room *save_fin = fin;
    t_room *pivot = debut;

    if (debut->sl == fin->sl)
        return;
	while (1)
	{
		while (fin->sl > pivot->sl)
			fin = fin->prev;
		while (debut->sl < pivot->sl)
			debut = debut->next;
		if (debut->sl < fin->sl)
			echanger(debut->prev, debut, fin, fin->prev, l);
		else break;
	}
	quickSort(l->rooms, debut, l);
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
