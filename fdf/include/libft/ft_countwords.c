/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:16:53 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 11:54:12 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_countwords(char const *s)
{
	unsigned int	is;
	unsigned int	j;

	is = 0;
	j = 0;
	if (!s || !*s)
		return (0);
	while (s[is] != '\0')
	{
		while ((s[is] >= 9 && s[is] <= 13) || s[is] == 32)
			is++;
		if (!((s[is] >= 9 && s[is] <= 13) || s[is] == 32) && s[is] != '\0')
			j++;
		while (!((s[is] >= 9 && s[is] <= 13) || s[is] == 32) && s[is] != '\0')
			is++;
	}
	return (j);
}
