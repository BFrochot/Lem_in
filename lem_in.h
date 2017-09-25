/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrochot <bfrochot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:06:38 by bfrochot          #+#    #+#             */
/*   Updated: 2017/09/25 22:21:51 by bfrochot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN
# define LEM_IN

# include "./libft/libft.h"
# include <errno.h>

typedef struct	s_lem
{
	struct s_lem	*next;
	struct s_lem	*prev;
	char			*name;
	int				x;
	int				y;
	int				nb;
	char			*links;
	struct s_lem	*start;
	struct s_lem	*end;
}				t_lem;

#endif
