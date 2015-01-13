/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:21:30 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/14 16:22:12 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;

	if (size == 0)
		return (NULL);
	if (!(str = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	return (ft_memset(str, 0, size));
}
