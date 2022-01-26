/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:54:32 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/26 10:19:55 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;
	char *line;
	ssize_t	ret = 0;
	line = (char *)malloc(sizeof(66));

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("unable to open file\n");
	ret = get_next_line(fd, &line);
	printf("copied string: %s\n", line);
	printf("ret = %zd\n", ret);
	free(line);
	return (0);
}



// if (a < 7)
// 	a = someValue
// else
// 	a = someOtherValue;
// you can write
// a = a < 7 ? someValue : someOtherValue;






// int	get_line_length(const int fd)
// {
// 	char	c;
// 	int		ret;

// 	ret = 0;
// 	while (read (fd, &c, 1) > 0 && c != '\n')
// 		ret++;
// 	return (ret);
// }

// int	number_of_lines(const int fd)
// {
// 	char	c;
// 	int		nbr_lines;

// 	nbr_lines = 0;
// 	while (read (fd, &c, 1) > 0)
// 	{
// 		if (c == '\n')
// 			nbr_lines++;
// 	}
// 	return (nbr_lines);
// }