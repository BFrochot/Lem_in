/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cosi <cosi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/10/03 02:01:03 by cosi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN
# define SIZE 5000000

# include "./libft/libft.h"

typedef struct		s_room
{
	struct s_room	*next;
	struct s_room	*prev;
	char			*name;
	int				nam;
	int				x;
	int				y;
	int				ant;
	int				dist;
	int				dist2;
	int				sl;
	struct s_room	**links;
}					t_room;

typedef struct		s_lem
{
	struct s_room	*start;
	struct s_room	*end;
	struct s_room	*rooms;
	struct s_room	*time;
	int				nb;
	char			E;
	char			G;
	char			C;
	char			fast;
	char			link;
	char			start_opt;
	char			end_opt;
	int				max;
	int				line_nb;
	char			command;
	char			error;
	char			*rendu;
	int				len;
}					t_lem;

void				init_lem(t_lem *lem);
void				error_p(void);
void				error(int i, t_lem *l);
void				reading(char *line, t_lem *lem);
void				links(char *line, t_lem *lem, int i);
void				free_tab(char **t);
void				rooms(char *line, t_lem *l);
t_room				*corres(char *str, t_lem *l);
t_room 				*corres_links(int i, t_lem *l);
void				putmove(char *ito, char *str, char C);
void				set_dist(t_room *r, int i, t_lem *l);
void				set_dist2(t_room *r, int i, t_lem *l);
void				short_links(t_room *r);
void				sort_by_short_links(t_lem *l, char done, t_room *prev);
void				quicksort(t_room *debut, t_room *fin, t_lem *l);
void				resol(t_lem *l);

#endif
