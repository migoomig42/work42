/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:48:24 by jumiguel          #+#    #+#             */
/*   Updated: 2014/11/21 17:50:19 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != (char)c && str[i])
		i++;
	if (str[i] == (char)c)
		return (str + i);
	else
		return (NULL);
}
