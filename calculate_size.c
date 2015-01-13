/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:59:47 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/13 19:46:49 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		size_list(t_list *list)
{
	t_list		*temp;
	t_point		*temp2;
	t_size		pos;

	temp = list;

	while (temp)
	{
		temp2 = temp->point;
		while (temp2)
		{
			if (temp2->x < pos.xmin)
				pos.xmin = temp2->x;
			if (temp2->x > pos.xmax)
				pos.xmax = temp2->x;
			if (temp2->y < pos.ymin)
				pos.ymin = temp2->y;
			if (temp2->y > pos.ymax)
				pos.ymax = temp2->y;
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (pos);
}
