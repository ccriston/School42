/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:42:40 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/03 15:00:26 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_sqrt(unsigned int nb)
{
	unsigned int	a;

	a = 1;
	if (nb == 1)
		return (1);
	if (nb > 0)
	{
		while (a * a < nb)
			a++;
		if (nb % a == 0)
			return (a);
	}
	return (0);
}
