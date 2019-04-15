/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:59:22 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 16:23:31 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char *s;

	d = dst;
	s = src;
	if (dst == src)
		return (dst);
	while (n-- > 0)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
