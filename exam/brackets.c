/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:39:25 by ccriston          #+#    #+#             */
/*   Updated: 2019/06/05 11:48:45 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		brack(char *av)
{
	int i;
	int j;
	char	br[10000];

	i = 0;
	j = 0;
	while (av[j] != '\0')
	{
		if (av[j] == '(' || av[j] == '[' || av[j] == '{')
		{
			br[i] = av[j];
			i++;
		}
		if (av[j] == ')')
		{
			if (br[i-1] == '(')
				i--;
			else
			{
				write(1, "error\n", 6);
				return (1);
			}
		}
		if (av[j] == ']')
		{
		  	if (br[i-1] == '[')
				i--;
			else
			{
				write(1, "error\n", 6);
				return (1);
			}
		}
		if (av[j] == '}')
		{
			if (br[i-1] == '{')
				i--;
			else
			{
				write(1, "error\n", 6);
				return (1);
			}
		}
		j++;
	}
	write(1, "OK\n", 3);
	return (0);
}


int main (int ac, char **av)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	if (ac >= 2)
	{
		while (++k < ac)
			i = brack(av[k]);
	}
	if (ac < 2)
		write(1, "\n", 1);
	return (0);
}
