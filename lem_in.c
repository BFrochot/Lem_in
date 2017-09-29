/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:26 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/28 21:53:27 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	options(int ac, char **arg, t_lem *lem)
{
	int i;

	while (--ac)
	{
		if (arg[ac][0] != '-')
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
	if (ret == 0)
		error(21, lem);
	lem->nb = ft_atoi(nb);
	lem->rendu = ft_strjoinfree(lem->rendu, nb, 3);
	lem->rendu = ft_strjoinfree(lem->rendu, "\n", 1);
}

void	init_lem(int ac, char **arg, t_lem *lem)
{
	lem->start = NULL;
	lem->end = NULL;
	lem->rooms = NULL;
	lem->E = 0;
	lem->G = 0;
	lem->C = 0;
	lem->link = 0;
	lem->line_nb = 1;
	lem->command = 0;
	lem->error = 0;
	lem->nam = 0;
	lem->max = 0;
	lem->rendu = ft_strdup("");
	options(ac, arg, lem);
	if (lem->C)
		ft_putstr("\033[32m");
	nb_ants(lem);
}

int		main(int ac, char **arg)
{
	char	*line;
	int		ret;
	t_lem	*lem;

	lem = palloc(sizeof(t_lem));
	init_lem(ac, arg, lem);
	while ((ret = get_next_line(0, &line)) != -1 && ret != 0
			&& ++(lem->line_nb) && (!lem->error || lem->E))
	{
		reading(line, lem);
		if (!lem->error)
		{
			lem->rendu = ft_strjoinfree(lem->rendu, line, 3);
			lem->rendu = ft_strjoinfree(lem->rendu, "\n", 1);
		}
		else
			free(line);
	}
	if (ret == -1)
		error_p();
	lem->rendu = ft_strjoinfree(lem->rendu, "\n", 1);
	resol(lem);
	return (0);
}
