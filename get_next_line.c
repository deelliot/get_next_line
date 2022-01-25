/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/25 12:07:49 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	ssize_t	ret;
	char	buf[MAX_FD + 1];
	ssize_t	size;
	int		i;

	ret = 0;
	size = BUFF_SIZE + 1;
	i = 0;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	ret = read(fd, buf, size);

	while (ret > -1)
	{
		while (i < BUFF_SIZE)
		{
			if (buf[i] == '\n')
			{
				ft_strncpy(*line, buf, i);
				return (1);
			}
			i++;
		}

	}
	return (-1);
}