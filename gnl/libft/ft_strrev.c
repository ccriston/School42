/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:03:28 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 11:52:04 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			c;

	if (str && *str)
	{
		j = 0;
		while (str[j] != '\0')
			j++;
		j--;
		i = 0;
		while (i < j)
		{
			c = str[i];
			str[i] = str[j];
			str[j] = c;
			i++;
			j--;
		}
		return (str);
	}
	return (NULL);
}
