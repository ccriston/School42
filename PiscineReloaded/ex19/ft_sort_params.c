/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:59:11 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/02 16:42:12 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **s1, char **s2)
{
	char *buff;

	buff = *s1;
	*s1 = *s2;
	*s2 = buff;
}

int		main(int ac, char **av)
{
	int a;

	if (ac == 2)
		ft_putstr(av[1]);
	if (ac > 2)
	{
		while (ac > 0)
		{
			a = 1;
			while (av[a + 1] != '\0')
			{
				if (ft_strcmp(av[a], av[a + 1]) > 0)
					ft_swap(&av[a], &av[a + 1]);
				a++;
			}
			ac--;
		}
		a = 1;
		while (av[a] != '\0')
		{
			ft_putstr(av[a]);
			a++;
		}
	}
	return (0);
}
