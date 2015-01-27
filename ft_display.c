/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:53:37 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/27 18:33:41 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == 65307)
		exit (0);
	ft_putnbr(keycode);
	return (0);
}

int		expose_hook(t_env *env)
{
	final_fantasy(env->list, env);
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
	var.win = mlx_new_window(var.mlx, var.size->pad * var.size->xmax, var.size->pad * var.size->ymax, "42");
	mlx_key_hook(var.win, key_hook, &var);
	mlx_expose_hook(var.win, expose_hook, &var);
	mlx_loop(var.mlx);
}
