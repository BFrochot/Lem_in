/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:26 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/30 02:51:32 by cosi             ###   ########.fr       */
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
			else if (arg[ac][i] == 'F')
				lem->fast = 1;
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
	lem->fast = 0;
	lem->link = 0;
	lem->line_nb = 1;
	lem->command = 0;
	lem->error = 0;
	lem->nam = 0;
	lem->max = 0;
	lem->len = 0;
	lem->rendu = ft_strdup("");
	options(ac, arg, lem);
	if (lem->C)
		ft_putstr("\033[32m");
	nb_ants(lem);
}

char	*join(char *str, char *s2, t_lem *l)
{
	char	*new;
	int		i;
	int		j;

	if (l->len == 0)
		l->len = ft_strlen(str);
	l->len = ft_strlen(s2) + l->len + 1;
	new = palloc(l->len + 1);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\n';
	new[i + j + 1] = 0;
	free(str);
	free(s2);
	return (new);
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
		if (!(lem->error) && !(lem->fast))
			lem->rendu = join(lem->rendu, line, lem);
		else
			free(line);
	}
	if (ret == -1)
		error_p();
	resol(lem);
	return (0);
}
