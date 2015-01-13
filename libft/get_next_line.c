/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 18:34:19 by jumiguel          #+#    #+#             */
/*   Updated: 2015/01/12 17:37:19 by jumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_make_save(char *s1)
{
	static char	*save;

	if (!s1)
	{
		s1 = save;
		save = NULL;
	}
	else if (*s1)
		save = ft_strdup(s1);
	else
		save = NULL;
	return (s1);
}

int		ft_check(char **line)
{
	int		i;
	char	*buffer;

	*line = ft_make_save(NULL);
	if ((buffer = ft_strchr(*line, '\n')))
	{
		i = buffer - *line;
		buffer = ft_strdup(&buffer[1]);
		(*line)[i] = '\0';
		ft_make_save(buffer);
		ft_memdel((void **)&buffer);
		return (1);
	}
	return (0);
}

void	ft_join(char **line, char *buffer)
{
	char	*str;

	str = *line;
	*line = ft_strjoin(*line, buffer);
	ft_memdel((void **)&str);
}

int		ft_control_error(int const fd, char **line)
{
	if (fd < 0)
		return (-1);
	if (ft_check(line) == 1)
		return (1);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	char	*buffer;
	int		i;
	int		ret;

	if ((i = ft_control_error(fd, line)) != 0)
		return (i);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\0')
			ft_join(line, buffer);
		else
		{
			buffer[i] = '\0';
			ft_join(line, buffer);
			ft_make_save(&buffer[i + 1]);
			ft_memdel((void **)&buffer);
			return (1);
		}
	}
	return (*line ? 1 : 0);
}
