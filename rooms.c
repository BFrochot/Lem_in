/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:17:12 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/03 02:03:59 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	first_room(char *str, t_lem *l, int x, int y)
{
	l->rooms = palloc(sizeof(t_room));
	l->rooms->next = NULL;
	l->rooms->prev = NULL;
	l->rooms->name = str;
	l->rooms->x = x;
	l->rooms->y = y;
	l->rooms->ant = 0;
	l->rooms->dist = -1;
	l->rooms->dist2 = -1;
	l->rooms->sl = 0;
	l->rooms->links = 0;
	if (l->start_opt)
		l->start = l->rooms;
	if (l->end_opt)
		l->end = l->rooms;
}

void	new_room(char *str, int x, int y, t_lem *l)
{
	l->time->next = palloc(sizeof(t_room));
	l->time->next->next = NULL;
	l->time->next->prev = l->time;
	l->time->next->name = str;
	l->time->next->x = x;
	l->time->next->y = y;
	l->time->next->ant = 0;
	l->time->next->dist = -1;
	l->time->next->dist2 = -1;
	l->time->next->sl = 0;
	l->time->next->links = 0;
	if (l->start_opt)
		l->start = l->time->next;
	if (l->end_opt)
		l->end = l->time->next;
	l->time = l->time->next;
}

void	add_room(char *str, t_lem *l, int x, int y)
{
	t_room *r;

	r = l->rooms;
	while (r && (l->time = r))
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
		else if (r->x == x && r->y == y)
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

void	rooms2(char *line, t_lem *l, char *str, int j, int x)
{
	int		y;

	y = ft_atoi(line + j);
	if (!line[j])
		error(11, l);
	while (line[j] && line[j] != ' ')
		++j;
	while (line[j] && line[j] != ' ')
		++j;
	if (line[j])
		error(8, l);
	if (!l->error)
	{
		if (!l->rooms)
			first_room(str, l, x, y);
		else
			add_room(str, l, x, y);
	}
	else
		free(str);
}

void	rooms(char *line, t_lem *l)
{
	int		i;
	int		j;
	char	*str;
	int		x;

	i = -1;
	while (line[++i] && line[i] == ' ')
		;
	if (line[i] == 'L')
		error(9, l);
	j = i;
	while (line[j] && line[j] != ' ')
		++j;
	str = ft_strsub(line, i, j - i);
	while (line[j] && line[j] == ' ')
		++j;
	x = ft_atoi(line + j);
	while (line[j] && line[j] != ' ')
		++j;
	while (line[j] && line[j] == ' ')
		++j;
	rooms2(line, l, str, j, x);
}
