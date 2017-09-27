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
	if (i == 0 || i == 20)
	{
		if (!i)
			ft_putstr_fd("lem_in: illegal option\n", 2);
		ft_putstr_fd("usage: lem_in [-ECG]\n", 2);
		exit(2);
	}
	if (l->E)
	{
		if (i == 1)
		{
			ft_putstr_fd("Error : First line must contain only digits.\n", 2);
			exit(i);
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
			ft_putstr_fd(", multiple words.\n", 2);
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
			ft_putstr_fd(", link with non existant room.\n", 2);
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
		else if (i == 12)
		{
			ft_putstr_fd("Error : can't reach the end.\n", 2);
			exit(i);
		}
		else if (i == 13)
		{
			ft_putstr_fd("Error : start not set.\n", 2);
			exit(i);
		}
		else if (i == 14)
		{
			ft_putstr_fd("Error : end not set.\n", 2);
			exit(i);
		}
		if (i == 21)
		{
			ft_putstr_fd("Error : No input.\n", 2);
			exit(i);
		}
	}
	if (i == 1 || i == 12 || i == 13 || i == 14)
	{
		ft_putstr("ERROR\n");
		exit(i);
	}
}
