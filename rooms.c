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
	++(l->nam);
	l->rooms->nam = l->nam;
	l->rooms->sl = 0;
	l->rooms->links = palloc(sizeof(int));
	(l->rooms->links)[0] = 0;
	if (l->start_opt)
		l->start = l->rooms;
	if (l->end_opt)
		l->end = l->rooms;
}

void	new_room(char *str, int x, int y, t_lem *l)
{
	l->time->next = palloc(sizeof(t_room));
	l->time->next->next = NULL;
	l->time->next->name = str;
	++(l->nam);
	l->time->next->nam = l->nam;
	l->time->next->x = x;
	l->time->next->y = y;
	l->time->next->ant = 0;
	l->time->next->dist = -1;
	l->time->next->sl = 0;
	l->time->next->links = palloc(sizeof(int));
	(l->time->next->links)[0] = 0;
	if (l->start_opt)
		l->start = l->time->next;
	if (l->end_opt)
		l->end = l->time->next;
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
			free(str);
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
		l->time = r;
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
