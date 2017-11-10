/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:26 by bfrochot          #+#    #+#             */
/*   Updated: 2017/11/10 16:28:44 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	options(int ac, char **arg, t_lem *lem)
{
	int i;

	while (--ac)
	{
		if (arg[ac][0] != '-' || !arg[ac][1])
			error(20, lem);
		i = 0;
		while (arg[ac][++i])
		{
			if (arg[ac][i] == 'E')
				lem->E = 1;
			else if (arg[ac][i] == 'G')
				lem->G = 1;
			else if (arg[ac][i] == 'C')
				lem->C = 1;
			else if (arg[ac][i] == 'F')
				lem->fast = 1;
			else
				error(0, lem);
		}
	}
}

void	resize(t_lem *l)
{
	char	*n;
	int		i;
	int		j;

	n = palloc(SIZE + l->len);
	i = -1;
	j = -1;
	while (++i < l->len)
		n[++j] = l->rendu[i];
	free(l->rendu);
	l->rendu = n;
}

void	join(char *str, t_lem *l)
{
	int i;

	i = -1;
	while (str && str[++i])
	{
		if (l->len % SIZE == 0)
			resize(l);
		l->rendu[l->len++] = str[i];
	}
	if (l->nb != -1 || str == NULL)
	{
		if (l->len % SIZE == 0)
			resize(l);
		l->rendu[l->len++] = '\n';
	}
}

void	nb_ants(t_lem *lem)
{
	int		ret;
	char	buf[2];

	buf[1] = 0;
	while (!lem->error && (ret = read(0, buf, 1)) != 0 && ret != -1)
	{
		if (ft_isdigit(*buf))
			join(buf, lem);
		else if (*buf == '\n')
		{
			join(NULL, lem);
			break ;
		}
		else
			error(1, lem);
	}
	if (ret == -1)
		error_p();
	if (ret == 0)
		error(21, lem);
	lem->nb = ft_atoi(lem->rendu);
}

int		main(int ac, char **arg)
{
	char	*line;
	int		ret;
	t_lem	*lem;

	lem = palloc(sizeof(t_lem));
	init_lem(lem);
	options(ac, arg, lem);
	if (lem->C)
		ft_putstr("\033[32m");
	nb_ants(lem);
	while ((ret = get_next_line(0, &line)) != -1 && ret != 0
	&& ++(lem->line_nb) && (!lem->error || lem->E))
	{
		reading(line, lem);
		if (!(lem->error) && !(lem->fast))
			join(line, lem);
		free(line);
	}
	if (ret == -1)
		error_p();
	resol(lem);
	return (0);
}
