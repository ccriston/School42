/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:03:44 by ccriston          #+#    #+#             */
/*   Updated: 2019/06/05 15:19:20 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	bp(char *av)
{
	int	i;
	int	k;
	int	save;
	int	m;
	int	l;
	int	m1;

	i = 0;
	save = 0;
	m1 = 0;
	while (av[i] != '\0')
	{
		k = 0;
		m = 0;
		if (av[i] == av[i+1])
		{
			m = 1;
			if (av[i] == av[i-1])
			{
				while (av[i-m] == av[i+1+m])
					m++;
				if (av[i-m] == av[i+m])
					m = 0;
				else 
					m = 1;
			}
		}
		while (av[i - k] == av[i + m + k] && av[i+m+k] != '\0')
			k++;
		k--;
		if (save < k || (save == k && m1 <= m))
		{
			save = k;
			l = i;
			m1 = m;
		}
		i++;
	}
	i = l - save;
	l = l+m1+save;
	while (i <= l)
	{
		write(1, &av[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		bp(av[1]);
	write(1, "\n", 1);
	return (0);
}
