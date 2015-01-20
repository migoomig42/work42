/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:59:47 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/20 19:34:25 by jumiguel         ###   ########.fr       */
	/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_size		*ft_init_value(t_size *size, t_point *point)
{
	if ((size = (t_size *)malloc(sizeof(*size))))
	{
		size->xmin = point->x;
		size->ymin = point->y;
		size->xmax = point->x;
		size->ymax = point->y;
	}
	return (size);
}

void		set_value(t_size *min_max, t_point *temp2)
{
	if (min_max->xmin > temp2->x)
		min_max->xmin = temp2->x;
	if (min_max->ymin > temp2->y)
		min_max->ymin = temp2->y;
	if (min_max->xmax < temp2->x)
		min_max->xmax = temp2->x;
	if	(min_max->ymax < temp2->y)
		min_max->ymax = temp2->y;
}

t_size		*scaling_my_baby(t_point *point, t_list *list)
{
	t_list *temp;
	t_point *temp2;
	t_size	*min_max;

	min_max = ft_init_value(min_max, point);
	temp = list;
	while (temp)
	{
		temp2 = temp->point;
		while (temp2)
		{
			set_value(min_max, temp2);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	if (min_max->xmax > min_max->ymax)
		min_max->pad = MAX / min_max->xmax;
	else
		min_max->pad =  MAX / min_max->ymax;
	return (min_max);
}
