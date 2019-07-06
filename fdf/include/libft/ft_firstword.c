/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firstword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:50:22 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/14 11:39:36 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_firstword(char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*word;

	if (!str || !(*str))
		return (NULL);
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	j = i;
	while (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	word = (char *)malloc(sizeof(char) * (i - j + 1));
	k = 0;
	while (j < i)
	{
		word[k] = str[j];
		k++;
		j++;
	}
	word[k] = '\0';
	return (word);
}
