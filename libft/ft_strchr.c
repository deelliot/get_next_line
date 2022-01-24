/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:58:56 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/11 17:58:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	while (*string)
	{
		if (*string == c)
		{
			return ((char *)string);
		}
		string++;
	}
	if (c == '\0')
	{
		return ((char *)string);
	}
	return (NULL);
}
