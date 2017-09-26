/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:26 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/26 11:12:32 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	options(int ac, char **arg, t_lem *lem)
{
	int i;

	while (--ac)
	{
		if (arg[ac][0] != '-')
			error(0, lem);
		i = 0;
		while (arg[ac][++i])
		{
			if (arg[ac][i] == 'E')
				lem->E = 1;
			else if (arg[ac][i] == 'G')
				lem->G = 1;
			else
				error(0, lem);
		}
	}
}

void	nb_ants(t_lem *lem)
{
	int ret;
	char *nb;
	char buf[2];

	buf[1] = 0;
	nb = ft_strdup(buf);
	while (!lem->error && (ret = read(0, buf, 1)) != 0 && ret != -1)
	{
		if (ft_isdigit(*buf))
			nb = ft_strjoinfree(nb, buf, 1);
		else if (*buf == '\n')
			break;
		else
			error(1, lem);
	}
	if (ret == -1)
		error_p();
	lem->nb = ft_atoi(nb);
	free(nb);
}

void	init_lem(int ac, char **arg, t_lem *lem)
{
	lem->start = NULL;
	lem->end = NULL;
	lem->rooms = NULL;
	lem->E = 0;
	lem->G = 0;
	lem->link = 0;
	lem->line_nb = 0;
	lem->command = 0;
	lem->error = 0;
	options(ac, arg, lem);
	nb_ants(lem);
}

void	truc(t_lem *lem)
{
	t_room *r;
	int i;

	r = lem->rooms;
	while (r)
	{
		ft_putstr(r->name);
		ft_putstr(" ");
		ft_putnbr(r->x);
		ft_putstr(" ");
		ft_putnbr(r->y);
		ft_putstr(" et dist = ");
		ft_putnbr(r->dist);
		ft_putstr("\n");
		i = -1;
		while (r->links[++i])
		{
			ft_putstr(r->links[i]);
			ft_putstr("\n");
		}
		r = r->next;
	}
}


int		main(int ac, char **arg)
{
	char	*line;
	int		ret;
	t_lem	*lem;

	lem = palloc(sizeof(t_lem));
	init_lem(ac, arg, lem);
	if (lem->error)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (3);
	}
	while ((ret = get_next_line(0, &line)) != -1 && ret != 0
			&& ++(lem->line_nb) && (!lem->error || lem->E))
	{
		reading(line, lem);
		free(line);
	}
	if (ret == -1)
		error_p();
	resol(lem->end, 0, lem);
	sol(lem);
	truc(lem);
	return (0);
}
