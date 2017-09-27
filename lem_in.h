/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/27 11:34:00 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "./libft/libft.h"

typedef struct		s_room
{
	struct s_room	*next;
	char			*name;
	int				x;
	int				y;
	int				ant;
	int				dist;
	int				nb_short_links;
	int				max;
	char			**links;
}					t_room;

typedef struct		s_lem
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*rooms;
	int				nb;
	char			E;
	char			G;
	char			C;
	char			link;
	char			start_opt;
	char			end_opt;
	int				line_nb;
	char			command;
	char			error;
	char			*rendu;
}					t_lem;

void				error_p(void);
void				error(int i, t_lem *l);
void				reading(char *line, t_lem *lem);
void				links(char *line, t_lem *lem, int i);
void				free_tab(char **t);
void				rooms(char *line, t_lem *l);
t_room				*corres(char *str, t_lem *l);
void				putmove(int i, char *str, char C);
void				set_dist(t_room *r, int i, t_lem *l);
void				resol(t_lem *l);

#endif
