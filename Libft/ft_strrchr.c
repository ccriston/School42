/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:29:00 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/10 14:55:42 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	if (!s && c != '\0')
		return (NULL);
	while (s[i] != '\0')
		i++;
	while (s[i] != (char)c && i >= 0)
		i--;
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
