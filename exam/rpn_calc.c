/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:10:37 by ccriston          #+#    #+#             */
/*   Updated: 2019/06/05 15:10:14 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	rpn (char *av)
{
	int	arr[10000];
	int	i;
	int k;

	k = 0;
	i = 0;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <='9')
		{
			arr[k] = atoi(av + i);
			k++;
			while (av[i] >= '0' && av[i] <= '9')
				i++;
		}
		else if (av[i] == ' ')
			i++;
		else if (av[i] == '*')
		{
			if (k < 2)
			{
				write(1, "Error\n",6);
				return ;
			}
//			printf("%d\n", arr[k-2]);
			arr[k-2] = arr[k-1]*arr[k-2];
//			printf("%d\n",arr[k-2]);
			k--;
			i++;
		}
		else if (av[i] == '+')
		{
			if (k < 2)
			{
				write(1, "Error\n",6);
				return ;
			}
//					printf("%d\n", arr[k-2]);
					arr[k-2] = arr[k-1]+arr[k-2];
//					printf("%d\n", arr[k-2]);
			k--;
			i++;
		}
		else if (av[i] == '-')
		{
			if (k < 2)
			{
				write(1, "Error\n",6);
				return ;
			}
//					printf("%d\n", arr[k-2]);
					arr[k-2] = arr[k-2]-arr[k-1];
//					printf("%d\n", arr[k-2]);
			k--;
			i++;
		}
		else if (av[i] == '/')
		{
			if (k < 2)
			{
				write(1, "Error\n",6);
				return ;
			}
//					printf("%d\n", arr[k-2]);
			arr[k-2] = arr[k-2]/arr[k-1];
//					printf("%d\n", arr[k-2]);
			k--;
			i++;
		}
		else if (av[i] == '%')
		{
			if (k < 2)
			{
				write(1, "Error\n",6);
				return ;
			}
//					printf("%d\n", arr[k-2]);
			arr[k-2] = arr[k-2] % arr[k-1];
//					printf("%d\n", arr[k-2]);
			k--;
			i++;
		}
		else
		{
			write(1, "Error\n",6);
			return ;
		}
	}
	if (k == 1)
		printf("%d",arr[0]);
	else
		write(1, "Error\n",6);
//	printf("k = %d", k);
//	printf("res = %d", arr[0]);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		rpn(av[1]);
	}
	else
		write(1, "Error\n",6);
	return (0);
}
