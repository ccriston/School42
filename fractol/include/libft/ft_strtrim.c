/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:07:30 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/13 19:13:47 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_delpr(char const *s, int i)
{
	int k;

	k = i - 1;
	while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && k >= 0)
	{
		k--;
		i--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = ft_delpr(s, ft_strlen(s));
	k = 0;
	while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && s[k] != '\0')
		k++;
	if ((i = i - k) < 0)
		i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	j = i + k;
	i = 0;
	while (s[k] != '\0' && k < j)
	{
		res[i] = (char)s[k];
		i++;
		k++;
	}
	res[i] = '\0';
	return (res);
}
