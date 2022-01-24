/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:45:11 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/17 23:14:50 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t						i;
	const unsigned char			*temp1 = (unsigned char *)s1;
	const unsigned char			*temp2 = (unsigned char *)s2;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (temp1[i] == temp2[i])
			i++;
		else
			break ;
	}
	return (temp1[i] - temp2[i]);
}
