/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:52:38 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/21 14:19:01 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*tab;
	t_list	*list;
	int		y;

	list = NULL;
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	y = 0;
	while (get_next_line(fd, &tab))
	{
		list = ft_add_list(list, tab, y);
		y++;
	}
	close(fd);
	display(list);
	return (0);
}
