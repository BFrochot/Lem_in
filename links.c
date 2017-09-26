#include "lem_in.h"

void	free_tab(char **t)
{
	int i;

	i = -1;
	while (t[++i])
		free(t[i]);
	free(t);
}

void	insert_link(t_room *r, char *str)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (lentab(r->links) + 2));
	i = -1;
	while (r->links[++i])
		new[i] = r->links[i];
	new[i] = str;
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
	if (!lem->error)
		insert_link(r, ft_strdup(t[0]));
	if (!lem->error)
		insert_link(corres(t[0], lem), ft_strdup(t[1]));
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
