/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:24:54 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/17 22:33:06 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_clear_front_whitespace(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_clear_end_whitespace(char const *s)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = len - 1;
	while (i > 0)
	{
		if (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s)
{
	unsigned int		i;
	unsigned int		beg;
	unsigned int		end;
	char				*newstr;

	i = 0;
	if (s == NULL)
		return (NULL);
	beg = ft_clear_front_whitespace(s);
	end = ft_clear_end_whitespace(s);
	if (beg == ft_strlen(s))
	{
		newstr = ft_strdup("");
		return (newstr);
	}
	newstr = (char *)malloc(sizeof(*newstr) * (end - beg + 2));
	if (newstr == NULL)
		return (NULL);
	while ((beg + i) <= end)
	{
		newstr[i] = s[beg + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
