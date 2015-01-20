/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:53:37 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/20 19:33:05 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			mlx_pixel_put(mlx, win, temp2->x * 10, temp2->y * 10, 0xFFFFFF);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

int		key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}

int		expose_hook(t_env *env)
{
	draw(env->mlx, env->win, env->list);
	return (0);
}

void	display(t_list *list)
{
	t_env	var;
	t_size	*size;

	*size = scaling_my_baby(list);
	var.mlx = mlx_init();
	var.list = list;
	var.win = mlx_new_window(var.mlx, size->xmax, size->ymax, "42");
	mlx_key_hook(var.win, key_hook, &var);
	draw(var.mlx, var.win, list);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_loop(var.mlx);
}
