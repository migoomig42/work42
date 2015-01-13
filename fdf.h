/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 14:34:13 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/12 21:03:52 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

typedef struct			s_env
{
	void	*mlx;
	void	*win;
}						t_env;

t_list		*ft_add_list(t_list *list, char *str, int y);
#endif
