/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:17:33 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/13 10:11:12 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;

	if (!dst || !src)
		return (NULL);
	i = 0;
	tempdst = (unsigned char *)dst;
	tempsrc = (const unsigned char *)src;
	while (i < n)
	{
		if (tempsrc[i] == (unsigned char)c)
		{
			tempdst[i] = tempsrc[i];
			i++;
			return (dst + i);
		}
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (NULL);
}
