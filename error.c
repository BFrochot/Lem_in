#include "lem_in.h"

void	error_p(void)
{
	perror(NULL);
	exit(errno);
}

void	error(int i, t_lem *l)
{
	if (!l->error && i != 2)
		l->error = 1;
	if (i == 0)
	{
		ft_putstr_fd("lem_in: illegal option\nusage: lem_in [-EG]\n", 2);
		exit(2);
	}
	if (l->E)
	{
		if (i == 1)
		{
			ft_putstr_fd("Error : First line must contain only digits.\n", 2);
			exit(3);
		}
		else if (i == 2)
		{
			ft_putstr_fd("Care : line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", no command.\n", 2);
		}
		else if (i == 3)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", words after link.\n", 2);
		}
		else if (i == 4)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", multiple links.\n", 2);
		}
		else if (i == 5)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", link to nothing.\n", 2);
		}
		else if (i == 6)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", should be a link, but isn't.\n", 2);
		}
		else if (i == 7)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", link with inexistant room.\n", 2);
		}
		else if (i == 8)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", too much words.\n", 2);
		}
		else if (i == 9)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", room name can't start with 'L'.\n", 2);
		}
		else if (i == 10)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", rooms coordinates must contain only digits.\n", 2);
		}
		else if (i == 11)
		{
			ft_putstr_fd("Error line ", 2);
			ft_putnbr_fd(l->line_nb, 2);
			ft_putstr_fd(", room missing coordinates.\n", 2);
		}
	}
}
