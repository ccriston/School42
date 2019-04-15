/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:27:24 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 16:19:03 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lmap;

	if (lst && f)
	{
		lmap = (f)(lst);
		lmap->next = ft_lstmap(lst->next, f);
		return (lmap);
	}
	return (NULL);
}
