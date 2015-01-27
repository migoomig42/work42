/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:05:58 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/27 18:33:30 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_x(t_draw *dw, t_env *env, t_size *size)
{
	dw->cumul = dw->dx / 2;
	dw->i = 1;
	while (dw->i <= dw->dx)
	{
		dw->x += dw->xinc;
		dw->cumul += dw->dy;
		if (dw->cumul >= dw->dx)
		{	
			dw->cumul -= dw->dx;
			dw->y += dw->yinc;
		}
		mlx_pixel_put(env->mlx, env->win, dw->x * size->pad, dw->y * size->pad, 0xFFFFFF);
		dw->i++;
	}
}

void	draw_y(t_draw *dw, t_env *env, t_size *size)
{
	dw->cumul = dw->dy / 2;
	dw->i = 1;
	while (dw->i <= dw->dy)
	{
		dw->y += dw->yinc;
		dw->cumul += dw->dx;
		if (dw->cumul >= dw->dy)
		{
			dw->cumul -= dw->dy;
			dw->x += dw->xinc;
		}
		mlx_pixel_put(env->mlx, env->win, dw->x * size->pad, dw->y * size->pad, 0xFFFFFF);
		dw->i++;
	}
}

void	draw_seg(t_point *i, t_point *f, t_env *env, t_size *size)
{
	t_draw	*dw;

	dw = NULL;
	dw->x = i->x;
	dw->y = i->y;
	dw->dx = f->x - i->x;
	dw->dy = f->y - i->y;
	dw->xinc = (dw->dx > 0) ? 1 : -1;
	dw->yinc = (dw->dy > 0) ? 1 : -1;
	dw->dx = abs(dw->dx);
	dw->dy = abs(dw->dy);
	mlx_pixel_put(env->mlx, env->win, dw->x * size->pad, dw->y * size->pad, 0xFFFFFF);
	if (dw->dx > dw->dy)
		draw_x(dw, env, size);
	else
		draw_y(dw, env, size);
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
				ligne(temp2->x * env->size->pad, temp2->y * env->size->pad, temp2->next->x * env->size->pad, temp2->next->y * env->size->pad, env);
			if (temp3)
			{
				ligne(temp2->x * env->size->pad, temp2->y * env->size->pad, temp3->x * env->size->pad, temp3->y * env->size->pad, env);
				temp3 = temp3->next;
			} 
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
