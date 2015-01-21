/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 15:58:22 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/21 15:33:19 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_point 	*ft_new_point(t_point *point, int x, int y, int z)
{
	t_point	*new;
	t_point	*temp;

	if (!(new = (t_point*)malloc(sizeof * new)))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	if (!point)
		return (new);
	else
	{
		temp = point;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (point);
	}
}

t_point		*ft_new_point_list(char *str, int y)
{
	char **tab;
	t_point *new;
	int x;
	int z;

	x = 0;
	tab = ft_strsplit(str, ' ');
	new = NULL;
	while (tab[x])
	{
		z = ft_atoi(tab[x]);
		new = ft_new_point(new, x, y, z);
		x++;
	}
	return (new);
}

t_list		*ft_add_list(t_list *list, char *line, int y)
{
	t_list	*new;
	t_list	*temp;

	if (!(new = (t_list*)malloc(sizeof * new)))
		return (NULL);
	new->point = ft_new_point_list(line, y); 
	new->next = NULL;
	if (!list)
		return (new);
	else
	{
		temp = list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		return (list);
	}
}
