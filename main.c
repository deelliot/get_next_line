/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:32 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/27 12:39:20 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int			fd;
	char		*line;
	ssize_t		ret;
	size_t		line_count;
	int			i;

	fd = 0;
	line_count = 0;
	i = 1;
	if (argc == 1)
	{
		printf("no file given");
		return (0);
	}
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			printf("unable to open file\n");
			return (0);
		}
		printf("\033[0;35m\n[START] file name: %s\tfd:%d\n\033[m", argv[i], fd);
		do{
			line_count++;
			ret = get_next_line(fd, &line);
			if (ret == 1)
			{
			printf("ret %zd\tline_nbr[%zu]: %s\n", ret, line_count, line);
			free(line);
			}
		}while (ret == 1);
		line = 0;
		printf("ret %zd\tline_nbr[%zu]: %s\n", ret, line_count, line);
		printf("\033[0;32m[DONE] file: %s\n\033[m", argv[i]);
		close(fd);
		i++;
		line_count = 0;
	}
	return (0);
}