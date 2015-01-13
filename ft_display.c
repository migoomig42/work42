/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:53:37 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/13 15:31:38 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_win()
{
	t_env	var;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 420, 420, "42");
	mlx_loop(var.mlx);
}

void	draw(void *mlx, void *win, t_list *list)
{
	t_list		*temp;
	t_point		*temp2;

	temp = list;
	while (temp)
	{
		temp2 = temp->point;
		while (temp2)
		{
			mlx_pixel_put(mlx, win, temp2->x, temp2->y, 0xFFFFFF);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	display_win();
}
