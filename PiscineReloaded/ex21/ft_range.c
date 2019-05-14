/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:41:33 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/03 11:18:22 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ran;
	int i;

	i = 0;
	if (min < max)
	{
		ran = (int *)malloc(sizeof(int) * (max - min));
		while (min < max)
		{
			ran[i] = min;
			min++;
			i++;
		}
		return (ran);
	}
	return (0);
}
