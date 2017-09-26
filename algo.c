#include "lem_in.h"

void	sol(lem)
{

}

t_room *corres(char *str, t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (ft_strcmp(r->name, str))
		r = r->next;
	return (r);
}

void	resol(t_room *r, int i, t_lem *l)
{
	int c;

	if (r->dist == -1 || r->dist > i)
		r->dist = i;
	else
		return ;
	c = -1;
	while (r->links[++c])
		resol(corres(r->links[c], l), i + 1, l);
}
