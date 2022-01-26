/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/26 12:02:20 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// The return value can be 1: a line has been read
// 						0:when the reading has been completed
// 						-1: an error has happened respectively.

int	get_next_line(const int fd, char **line)
{
	ssize_t		ret;
	char		buf[BUFF_SIZE + 1];
	static char	*temp_array[MAX_FD];
	char		*temp_str;
	ssize_t		i;

	i = 0;
	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (temp_array[fd] == NULL)
			temp_array[fd] = ft_strdup(buf);
		else
		{
			temp_str = ft_strjoin (temp_array[fd], buf);
			ft_strdel(&temp_array[fd]);
			temp_array[fd] = temp_str;
		}
		if (ft_strchr(temp_array[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret < 0)
	{
		ft_memdel ((void**) temp_array);
		return (-1);
	}
	else if (ret == 0 && temp_array[fd] == NULL)
	{
		ft_memdel ((void**)temp_array);
		return (0);
	}
	else
	{
		temp_str = NULL;
		while (temp_array[fd][i] != '\n' && temp_array[fd][i] != '\0')
			i++;
		if (temp_array[fd][i] == '\n')
		{
			*line = ft_strsub(temp_array[fd], 0, i);
			ft_strdel(temp_array);
		}
		else
		{
			*line = ft_strdup(temp_array[fd]);
			ft_strdel(temp_array);
		}
		return (1);
	}
}