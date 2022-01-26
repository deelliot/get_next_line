/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:32 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/26 11:53:35 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char 	*line;
	ssize_t	ret;
	int		line_nbr;

	line = NULL;
	line_nbr = 0;
	ret = 1;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("unable to open file\n");
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%d : %s\n", line_nbr, line);
		ft_strdel(&line);
		line_nbr++;
	}
	printf("line number: %d\n", line_nbr);
	return (0);
}
