/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:47:48 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/13 19:14:07 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_count(int nbr)
{
	int i;

	i = 0;
	while (nbr / 10 > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	i++;
	return (i);
}

static char		*ft_intmin(void)
{
	char	*nbr;

	if (!(nbr = (char *)ft_memalloc(sizeof(char) * (12))))
		return (NULL);
	nbr[0] = '-';
	nbr[1] = '2';
	nbr[2] = '1';
	nbr[3] = '4';
	nbr[4] = '7';
	nbr[5] = '4';
	nbr[6] = '8';
	nbr[7] = '3';
	nbr[8] = '6';
	nbr[9] = '4';
	nbr[10] = '8';
	nbr[11] = '\0';
	return (nbr);
}

static char		*ft_nbr(char *nbr, int n, int j, int i)
{
	int		prom;
	int		del;

	if (j == 1)
	{
		nbr[0] = '-';
		i--;
	}
	del = 1;
	while (--i >= 1)
		del = del * 10;
	while (del >= 1)
	{
		if (n / del < 10 && n / del != 0)
			nbr[j] = (n / del) + '0';
		else
		{
			prom = n / del;
			nbr[j] = (prom % 10) + '0';
		}
		del = del / 10;
		j++;
	}
	nbr[j + 1] = '\0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	char	*nbr;
	int		i;
	int		j;

	j = 0;
	if (n == -2147483648)
		return (ft_intmin());
	if (n < 0)
	{
		j = 1;
		n = -1 * n;
	}
	if (n == 0 || n == -0)
	{
		if (!(nbr = (char *)ft_memalloc(sizeof(char) * (2))))
			return (NULL);
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	i = j + ft_count(n);
	if (!(nbr = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	return (ft_nbr(nbr, n, j, i));
}
