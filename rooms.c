#include "lem_in.h"

void	first_room(char **t, t_lem *l)
{
	l->rooms = palloc(sizeof(t_room));
	l->rooms->next = NULL;
	l->rooms->name = *t;
	l->rooms->x = ft_atoi(t[1]);
	l->rooms->y = ft_atoi(t[2]);
	l->rooms->ant = 0;
	l->rooms->dist = -1;
	l->rooms->links = palloc(sizeof(char *));
	l->rooms->links[0] = 0;
	if (l->start_opt)
		l->start = l->rooms;
	if (l->end_opt)
		l->end = l->rooms;
}

void	new_room(char *str, int x, int y, t_lem *l)
{
	t_room *r;

	r = l->rooms;
	while (r->next)
		r = r->next;
	r->next = palloc(sizeof(t_room));
	r->next->next = NULL;
	r->next->name = str;
	r->next->x = x;
	r->next->y = y;
	r->next->ant = 0;
	r->next->dist = -1;
	r->next->links = palloc(sizeof(char *));
	r->next->links[0] = 0;
	if (l->start_opt)
		l->start = r->next;
	if (l->end_opt)
		l->end = r->next;
}

void	add_room(char *str, t_lem *l, int x, int y)
{
	t_room *r;

	r = l->rooms;
	while (r)
	{
		if (!ft_strcmp(r->name, str))
		{
			r->x = x;
			r->y = y;
			l->start = l->start_opt ? r : l->start;
			l->end = l->end_opt ? r : l->end;
			break ;
		}
		if (r->x == x && r->y == y)
		{
			free(r->name);
			r->name = str;
			l->start = l->start_opt ? r : l->start;
			l->end = l->end_opt ? r : l->end;
			break ;
		}
		r = r->next;
	}
	if (!r)
		new_room(str, x, y, l);
}

char	contain_digits(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

void	rooms(char *line, t_lem *l)
{
	char	**t;

	t = ft_strsplit(line, ' ');
	if (lentab(t) > 3)
		error(8, l);
	else if (lentab(t) < 3)
		error(11, l);
	else if (t[0][0] == 'L')
		error(9, l);
	else if (!contain_digits(t[1]) || !contain_digits(t[2]))
		error(10, l);
	if (!l->error)
	{
		if (!l->rooms)
			first_room(t, l);
		else
			add_room(*t, l, ft_atoi(t[1]), ft_atoi(t[2]));
		free(t[1]);
		free(t[2]);
		free(t);
	}
	else
		free_tab(t);
}
