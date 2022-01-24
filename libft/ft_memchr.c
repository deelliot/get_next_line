/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:26:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/12 15:47:00 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*p;
	size_t			i;

	temp = (unsigned char *)s;
	p = 0;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (temp[i] == (unsigned char)c)
		{
			p = &temp[i];
			return (p);
		}
		i++;
	}
	return (p);
}
