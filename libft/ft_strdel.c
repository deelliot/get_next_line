/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:09:36 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/25 17:02:59 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter the address of a string that need to be
// freed with free(3) then sets its pointer to NULL.

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (*as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
