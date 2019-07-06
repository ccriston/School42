/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:28:29 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/12 11:27:57 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*lst2;

	if (alst && *alst && del)
	{
		lst = *alst;
		while (lst != NULL)
		{
			lst2 = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = lst2;
		}
		*alst = NULL;
	}
}
