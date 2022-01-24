/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:30:45 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/13 11:57:04 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	if (!s1 && !s2)
		return (1);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	else
		return (0);
}
