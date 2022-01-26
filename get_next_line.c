/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/26 10:10:37 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// The return value can be 1: a line has been read
// 						0:when the reading has been completed
// 						-1: an error has happened respectively.

int	get_next_line(const int fd, char **line)
{
	ssize_t	ret;
	char	buf[MAX_FD + 1];
	ssize_t	size;
	int		i;
	char	temp[BUFF_SIZE];

	ret = 0;
	size = BUFF_SIZE + 1;
	i = 0;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	ret = read(fd, buf, size);
	if (ret < 0)
		return (-1);
	// remember to account for ret == 0
	while (ret > 0)
	{
		while (i < BUFF_SIZE)
		{
			if (buf[i] == '\n')
			{
				printf("i got to first nl\n");
				ft_strncpy(*line, buf, i);
				return (1);
			}
			else if (buf[i] != '\n' && (i + 1) == BUFF_SIZE)
			{
				ft_strncpy(temp, buf, i);
				i = 0;
				read(fd, &buf[i], size);
				if (buf[i] == '\n')
				{
					printf("i got to cat\n");
					ft_strncat (*line, buf, i);
					return (1);
				}
			}
			i++;
		}
	}
	return (-1);
}