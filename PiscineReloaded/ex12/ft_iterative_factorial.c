/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:20:48 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/03 15:25:33 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int res;

	res = nb;
	if (nb >= 0 && nb < 13)
	{
		if (nb == 1 || nb == 0)
			return (1);
		while (nb > 1)
		{
			res = res * (nb - 1);
			nb--;
		}
		return (res);
	}
	return (0);
}
