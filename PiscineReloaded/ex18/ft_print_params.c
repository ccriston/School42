/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:10:04 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/02 13:00:35 by ccriston         ###   ########.fr       */
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
}

int		main(int ac, char **av)
{
	int a;

	a = 1;
	if (ac > 1)
	{
		ac--;
		while (a <= ac)
		{
			ft_putstr(av[a]);
			a++;
			ft_putchar('\n');
		}
	}
	return (0);
}
