#include "lem_in.h"

void	free_tab(char **t)
{
	int i;

	i = -1;
	while (t[++i])
		free(t[i]);
	free(t);
}

int		ft_intlen(int *k)
{
	int i;

	i = 0;
	while (k[i])
		++i;
	return (i);
}

void	insert_link(t_room *r, int s)
{
	int		*new;
	int		i;
	char	d;

	d = 0;
	new = malloc(sizeof(int) * (ft_intlen(r->links) + 2));
	i = -1;
	while ((r->links)[++i])
	{
		new[i] = (r->links)[i];
		if (s == (r->links)[i])
			d = 1;
	}
	new[i] = d ? 0 : s;
	new[i + 1] = 0;
	free(r->links);
	r->links = new;
}

void	create_link(char **t, t_lem *lem)
{
	t_room *r;

	r = corres(t[0], lem);
	if (r == NULL)
		error(7, lem);
	if (r == NULL)
		return ;
	r = corres(t[1], lem);
	if (r == NULL)
		error(7, lem);
	if (r == NULL)
		return ;
	if (lem->E && !ft_strcmp(t[0], t[1]))
	{
		ft_putstr_fd("Care : line ", 2);
		ft_putnbr_fd(lem->line_nb, 2);
		ft_putstr_fd(", link to the same room.\n", 2);
	}
	else if (!lem->error)
	{
		insert_link(r, corres(t[0], lem)->nam);
		insert_link(corres(t[0], lem), corres(t[1], lem)->nam);
	}
	free_tab(t);
}

void	links(char *line, t_lem *lem, int i)
{
	char	**t;
	int		lenght;

	lem->link = 1;
	if (!ft_strchr(line, '-'))
	{
		error(6, lem);
		return ;
	}
	t = ft_strsplit(line, '-');
	lenght = lentab(t);
	if (lenght == 1)
	{
		free_tab(t);
		error(5, lem);
	}
	else if (lenght > 2)
	{
		free_tab(t);
		error(4, lem);
	}
	else
	{
		while (t[1][i] && t[1][i] != ' ')
			++i;
		while (t[1][i] && t[1][i] == ' ')
			++i;
		if (t[1][i])
			error(3, lem);
		else
			create_link(t, lem);
	}
}
