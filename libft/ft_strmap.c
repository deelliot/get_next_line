/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:50:55 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/11 22:01:19 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*newstr;
	int				len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	newstr = (char *)malloc(sizeof(*newstr) * (len + 1));
	i = 0;
	if (newstr != NULL)
	{
		while (s[i])
		{
			newstr[i] = f(s[i]);
			i++;
		}
		newstr[i] = '\0';
	}
	return (newstr);
}
