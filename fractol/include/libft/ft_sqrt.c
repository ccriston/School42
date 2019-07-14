/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 11:42:40 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/05 13:11:38 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int a;

	a = 1;
	if (nb == 1)
		return (1);
	if (nb > 0)
	{
		while (a * a < nb)
			a++;
		if (nb / a == 0)
			return (a);
	}
	return (0);
}