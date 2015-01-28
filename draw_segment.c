/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:05:58 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/28 17:10:47 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_x(t_draw dw, t_env *env)
{
	int		i;
	int		x;
	int		y;

	x = dw.xi;
	y = dw.yi;
	dw.cumul = dw.dx / 2;
	i = 1;
	while (i <= dw.dx)
	{
		x += dw.xinc;
		dw.cumul += dw.dy;
		if (dw.cumul >= dw.dx)
		{	
			dw.cumul -= dw.dx;
			y += dw.yinc;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		i++;
	}
}

void	draw_y(t_draw dw, t_env *env)
{
	int		i;
	int		x;
	int		y;

	x = dw.xi;
	y = dw.yi;
	dw.cumul = dw.dy / 2;
	i = 1;
	while (i <= dw.dy)
	{
		y += dw.yinc;
		dw.cumul += dw.dx;
		if (dw.cumul >= dw.dy)
		{
			dw.cumul -= dw.dy;
			x += dw.xinc;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, 0xFFFFFF);
		i++;
	}
}

void	draw_seg(t_point *temp1, t_point *temp2, t_env *env)
{
	t_draw		dw;

	dw.xi = temp1->x * env->size->pad;
	dw.yi = temp1->y * env->size->pad;
	dw.xf = temp2->x * env->size->pad;
	dw.yf = temp2->y * env->size->pad;
	dw.dx = dw.xf - dw.xi;
	dw.dy = dw.yf - dw.yi;
	dw.xinc = (dw.dx > 0) ? 1 : -1;
	dw.yinc = (dw.dy > 0) ? 1 : -1;
	dw.dx = abs(dw.dx);
	dw.dy = abs(dw.dy);
	mlx_pixel_put(env->mlx, env->win, dw.xf, dw.yf, 0xFFFFFF);
	if (dw.dx > dw.dy)
		draw_x(dw, env);
	else
		draw_y(dw, env);
}

void	final_fantasy(t_list *list, t_env *env)
{
	t_list	*temp;
	t_point	*temp2;
	t_point	*temp3;

	temp = list;
	while (temp)
	{
		temp2 = temp->point;
		if (temp->next != NULL)
			temp3 = temp->next->point;
		while (temp2)
		{
			if (temp2->next)
				draw_seg(temp2, temp2->next, env);
			if (temp3)
			{
				draw_seg(temp2, temp3, env);
				temp3 = temp3->next;
			} 
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
