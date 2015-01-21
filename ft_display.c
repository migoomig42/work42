/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:53:37 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/21 15:33:16 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(void *mlx, void *win, t_list *list, t_size *size)
{
	t_list		*temp;
	t_point		*temp2;

	ft_putstr("4: ");
	ft_putnbr(size->pad);
	ft_putchar('\n');
	temp = list;
	while (temp)
	{
		temp2 = temp->point;
		while (temp2)
		{
			mlx_pixel_put(mlx, win, temp2->x * size->pad, temp2->y * size->pad, 0xFFFFFF);
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
	draw(env->mlx, env->win, env->list, env->size);
	return (0);
}

void	display(t_list *list)
{
	t_env	var;
	t_size	*size;

	size = NULL;
	var.mlx = mlx_init();
	var.list = list;
	size = scaling_my_baby(list->point, list);
	var.size = size;
	ft_putstr("1: ");
	ft_putnbr(var.size->pad);
	ft_putchar('\n');
	var.win = mlx_new_window(var.mlx, var.size->pad * var.size->xmax, var.size->pad * var.size->ymax, "42");
	ft_putstr("2: ");
	ft_putnbr(var.size->pad);
	ft_putchar('\n');
	mlx_key_hook(var.win, key_hook, &var);
	ft_putstr("3: ");
	ft_putnbr(var.size->pad);
	ft_putchar('\n');
	draw(var.mlx, var.win, list, var.size);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_loop(var.mlx);
}
