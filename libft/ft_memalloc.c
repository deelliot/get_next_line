/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:55:36 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/11 15:09:34 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	if (size != 0)
	{
		temp = (void *)malloc(sizeof(*temp) * size);
		if (temp != NULL)
		{
			ft_bzero(temp, size);
			return (temp);
		}
	}
	return (NULL);
}
