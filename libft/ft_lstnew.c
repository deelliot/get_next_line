/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:30:25 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/13 15:22:28 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new_node;

	new_node = (t_list *)malloc(sizeof(*new_node));
	if (new_node)
	{
		if (content != NULL)
		{
			new_node->content = (void *)malloc(sizeof(*content) * content_size);
			if (new_node->content == NULL)
			{
				free(new_node);
				return (NULL);
			}
			ft_memcpy (new_node->content, content, content_size);
			new_node->content_size = content_size;
		}
		else
		{
			new_node->content = NULL;
			new_node->content_size = 0;
		}
		new_node->next = NULL;
		return (new_node);
	}
	return (new_node);
}
