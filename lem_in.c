/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:26 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/25 22:40:24 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	options(int ac, char **arg, t_lem *lem)
{
	int i;

	i = 1;
	while (--ac)
	{
		if (arg[ac][0] != '-')
		{
			ft_putstr("Usage\n");
			exit(2);
		}
		while (arg[ac][++i])
		{
			if (arg[ac][i] == 'E')
				lem->E = 1;
			else if (arg[ac][i] == 'G')
				lem->G = 1;
			else
			{
				ft_putstr("Usage\n");
				exit(2);
			}
		}
	}
}

void	nb_ants(t_lem *lem)
{
	int ret;
	char *nb;
	char buf[2];

	buf[1] = 0;
	nb = ft_strdup("");
	while ((ret = read(0, buf, 1)) != 0 && ret != -1)
	{
		if (ft_isdigit(*buf))
			nb = ft_strjoinfree(nb, buf, 1);
		else if (*buf == '\n')
			break;
		else
		{
			if (lem->E)
				ft_putstr_fd("Error : First line must contain only digits.\n", 2)
			else
				ft_putstr_fd("ERROR\n", 2);
			exit(3);
		}
	}
	lem->nb = atoi(nb);
	if (ret == -1)
	{
		perror(NULL);
		exit(errno);
	}
}

void	init_lem(lem)
{
	lem->E = 0;
	lem->G = 0;
}

int		main(int ac, char **arg)
{
	char *line;
	int ret;
	t_lem *lem;

	lem = palloc(sizeof(t_lem));
	init_lem(lem);
	options(ac, arg);
	nb_ants(lem);
	while ((ret = get_next_line(0, &line)) != -1 && ret != 0)
	{
		ft_putstr(line);
		ft_putstr("\n");
		free(line);
	}
	if (ret == -1)
	{
		perror(NULL);
		exit(errno);
	}
	return (0);
}
