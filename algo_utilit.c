#include "lem_in.h"

t_room *corres(char *str, t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (r && ft_strcmp(r->name, str))
		r = r->next;
	return (r);
}

void	putmove(int i, char *str, char C)
{
	char *s;
	char *ito;

	ito = ft_itoa(i);
	s = malloc(ft_strlen(ito) + ft_strlen(str) + C ? 3 + 18 : 3);
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

void	set_dist(t_room *r, int i, t_lem *l)
{
	int c;

	if (r->dist == -1 || r->dist > i)
		r->dist = i;
	else
		return ;
	if (l->end->max < r->dist)
		l->end->max = r->dist;
	if (r == l->start)
		return ;
	c = -1;
	while (r->links[++c])
		set_dist(corres(r->links[c], l), i + 1, l);
}

void	short_links(t_room *r, t_lem *l)
{
	int i;

	while (r)
	{
		i = -1;
		if (r->dist != -1)
			while (r->links[++i])
				if (corres(r->links[i], l)->dist == r->dist + 1)
					++(r->sl);
		r = r->next;
	}
}

void	sort_by_short_links(t_lem *l, char done)
{
	t_room *r;
	t_room *prev;
	t_room *sv;

	while (done)
	{
		done = 0;
		r = l->rooms;
		prev = NULL;
		while (r->next)
		{
			if (r->next->sl > r->sl)
			{
				done = 1;
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
