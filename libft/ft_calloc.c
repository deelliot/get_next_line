/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:27:16 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/11 15:04:33 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	if (count == 0 || size == 0)
		return (NULL);
	array = malloc(count * size);
	if (array == NULL)
		return (array);
	ft_bzero(array, count * size);
	return (array);
}
