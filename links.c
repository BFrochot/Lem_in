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
	new = palloc(sizeof(int) * (ft_intlen(r->links) + 2));
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

void	create_link(char *str1, char *str2, t_lem *lem)
{
	t_room *r;
	t_room *s;

	r = corres(str1, lem);
	if (r == NULL)
		error(7, lem);
	if (r == NULL)
		return ;
	s = corres(str2, lem);
	if (s == NULL)
		error(7, lem);
	if (s == NULL)
		return ;
	if (lem->E && !ft_strcmp(str1, str2))
	{
		ft_putstr_fd("Care : line ", 2);
		ft_putnbr_fd(lem->line_nb, 2);
		ft_putstr_fd(", link to the same room.\n", 2);
	}
	else if (!lem->error)
	{
		insert_link(s, r->nam);
		insert_link(r, s->nam);
	}
}

void	links(char *line, t_lem *lem, int i)
{
	char	*chr;

	chr = ft_strchr(line, '-');
	if (!chr)
	{
		error(6, lem);
		return ;
	}
	while (chr[i + 1] && chr[i + 1] == ' ')
		++i;
	if (!chr[i + 1])
		error(5, lem);
	else if (ft_strchr(chr + 1, '-'))
		error(4, lem);
	else
	{
		while (chr[i + 1] && chr[i + 1] != ' ')
			++i;
		while (chr[i + 1] && chr[i + 1] == ' ')
			++i;
		if (chr[i + 1])
			error(3, lem);
		else
		{
			i = 0;
			while (chr[i + 1] && chr[i + 1] != ' ')
				++i;
			chr[i + 1] = 0;
			*chr = 0;
			create_link(line, chr + 1, lem);
			*chr = '-';
		}
	}
}

// void	links(char *line, t_lem *lem, int i)
// {
// 	char	**t;
// 	int		lenght;

// 	lem->link = 1;
// 	if (!ft_strchr(line, '-'))
// 	{
// 		error(6, lem);
// 		return ;
// 	}
// 	t = ft_strsplit(line, '-');
// 	lenght = lentab(t);
// 	if (lenght == 1)
// 	{
// 		free_tab(t);
// 		error(5, lem);
// 	}
// 	else if (lenght > 2)
// 	{
// 		free_tab(t);
// 		error(4, lem);
// 	}
// 	else
// 	{
// 		while (t[1][i] && t[1][i] != ' ')
// 			++i;
// 		while (t[1][i] && t[1][i] == ' ')
// 			++i;
// 		if (t[1][i])
// 			error(3, lem);
// 		else
// 			create_link(t, lem);
// 	}
// }
