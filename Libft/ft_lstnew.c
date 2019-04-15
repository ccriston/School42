/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:18:47 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/11 15:59:40 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lone;

	lone = (t_list *)ft_memalloc(sizeof(t_list));
	if (lone == NULL)
	{
		return (NULL);
	}
	if (content == NULL)
	{
		lone->content = NULL;
		lone->content_size = 0;
	}
	else
	{
		if (!(lone->content = ft_memalloc(sizeof(t_list) * content_size)))
		{
			free(lone);
			return (NULL);
		}
		lone->content = ft_memcpy(lone->content, content, content_size);
		lone->content_size = content_size;
	}
	lone->next = NULL;
	return (lone);
}
