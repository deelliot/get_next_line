/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:53:36 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/28 12:36:50 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_transfer_heap(const int fd, char **line, char **heap)
{
	int		i;
	char	*temp;

	i = 0;
	while (heap[fd][i] != '\n' && heap[fd][i] != '\0')
		i++;
	*line = ft_strsub(heap[fd], 0, i);
	if (heap[fd][i] == '\n')
	{
		temp = ft_strdup(heap[fd] + i + 1);
		free (heap[fd]);
		heap[fd] = temp;
		if (heap[fd][0] == '\0')
			ft_strdel(&heap[fd]);
	}
	else
		ft_strdel(&heap[fd]);
	return (1);
}

static int	ft_check_file(const int fd, char **line, int ret, char **heap)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && heap[fd] == NULL)
		return (0);
	else
		return (ft_transfer_heap(fd, line, heap));
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*heap[MAX_FD];
	char		*temp;
	int			ret;

	if (fd < 0 || !line || fd > MAX_FD)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (heap[fd] == NULL)
			heap[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(heap[fd], buf);
			free (heap[fd]);
			heap[fd] = temp;
		}
		if (ft_strchr(heap[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ft_check_file (fd, line, ret, heap));
}
