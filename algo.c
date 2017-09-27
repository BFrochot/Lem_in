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
			putmove(sv - l->nb, l->end->name, l->C);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	exit(0);
}

void	start_move(t_lem *l, char first)
{
	int i;
	t_room *cor;

	i = -1;
	while (l->start->links[++i])
	{
		cor = corres(l->start->links[i], l);
		if (cor->ant == 0 && cor->dist - l->start->dist - l->start->ant < -1)
		{
			--(l->start->ant);
			cor->ant = l->nb - l->start->ant;
			if (!first)
				ft_putchar(' ');
			if (first)
				first = 0;
			putmove(cor->ant, cor->name, l->C);
		}
	}
}

void	advance(t_room *r, t_lem *l, char *first)
{
	int i;
	t_room *cor;

	i = -1;
	while (r->ant && r->links[++i])
	{
		cor = corres(r->links[i], l);
		if (cor->dist == 0 || (cor->dist < r->dist && cor->ant == 0))
		{
			cor->ant = cor->dist ? r->ant : ++(cor->ant);
			if (!(*first))
				ft_putchar(' ');
			if (*first)
				*first = 0;
			putmove(r->ant, cor->name, l->C);
			r->ant = r == l->start ? r->ant - 1 : 0;
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
	while (++i < l->end->max)
	{
		r = l->rooms;
		while (r)
		{
			if (r->dist == i && r->ant)
				advance(r, l, &first);
			r = r->next;
		}
	}
	if (l->start->ant)
		start_move(l, first);
}

void	resol(t_lem *l)
{
	if (!l->start)
		error(13, l);
	if (!l->end)
		error(14, l);
	l->end->max = 0;
	l->start->ant = l->nb;
	l->end->ant = 0;
	set_dist(l->end, 0, l);
	if (l->start->dist == -1)
		error(12, l);
	if (l->E)
		ft_putchar('\n');
	if (l->C)
		ft_putstr("\033[0m");
	ft_putstr(l->rendu);
	if (l->start->dist == 1 ||l->start->dist == 0) 
		finish(l, l->nb);
	short_links(l->rooms, l);
	sort_by_short_links(l, 1);
	while (l->end->ant != l->nb)
	{
		solve(l);
		ft_putchar('\n');
	}
}
