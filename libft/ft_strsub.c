/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:19:58 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/13 12:04:05 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*newstr;

	if (!s)
		return (NULL);
	i = 0;
	newstr = (char *)malloc(sizeof(*newstr) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	while (len > 0)
	{
		newstr[i] = s[start + i];
		i++;
		len--;
	}
	newstr[i] = '\0';
	return (newstr);
}
