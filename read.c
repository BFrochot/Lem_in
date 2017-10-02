/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:23:48 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/02 18:23:49 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	command(t_lem *lem, char **t)
{
	int		i;

	if (lem->link)
		error(15, lem);
	i = -1;
	while (t[++i])
	{
		if (!ft_strcmp(t[i], "start"))
			lem->start_opt = 1;
		else if (!ft_strcmp(t[i], "end"))
			lem->end_opt = 1;
		else
			error(16, lem);
		free(t[i]);
	}
	free(t);
	if (i == 0)
		error(2, lem);
	lem->command = 1;
}

void	no_command(t_lem *lem)
{
	lem->start_opt = 0;
	lem->end_opt = 0;
}

void	reading(char *line, t_lem *lem)
{
	int i;

	if (!lem->command)
		no_command(lem);
	if (*line == '#' || !(*line))
	{
		if (line[1] == '#')
			command(lem, ft_strsplit(line + 2, ' '));
		else if (!(*line))
			error(17, lem);
		return ;
	}
	else if (lem->link)
		links(line, lem, 0);
	else
	{
		i = 0;
		while (line[i] && line[i] != '-')
			++i;
		if (line[i] && (lem->link = 1))
			links(line, lem, 0);
		else
			rooms(line, lem);
	}
	lem->command = 0;
}
