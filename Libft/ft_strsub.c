/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:00:13 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/13 19:13:03 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*ps;
	size_t		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	if (!(ps = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[start] != '\0' && i < len)
	{
		ps[i] = str[start];
		start++;
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
