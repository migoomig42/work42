/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:34:13 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/21 15:33:22 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define MAX 1000

#include "libft/includes/libft.h"
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/includes/get_next_line.h"

typedef struct 			s_point
{
	int		x;
	int		y;
	int		z;
	struct s_point		*next;
}						t_point;

typedef struct			s_list
{
	t_point			*point;
	struct s_list	*next;
}						t_list;

typedef struct			s_size
{
	int		xmin;
	int		ymin;
	int		xmax;
	int		ymax;
	int		pad;
}						t_size;

typedef struct			s_env
{
	void	*mlx;
	void	*win;
	t_list	*list;
	t_size	*size;
}						t_env;


t_list		*ft_add_list(t_list *list, char *str, int y);
void		display(t_list *list);
void		draw(void *mlx, void *win, t_list *list, t_size *size);
t_size		*scaling_my_baby(t_point *point, t_list *list);

#endif
