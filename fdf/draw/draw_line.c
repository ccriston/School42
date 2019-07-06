/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:11:02 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/04 13:56:38 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	mabs(int n)
{
	if (n == -2147483648)
		return (2147483647);
	if (n < 0)
		return (n * -1);
	return (n);
}

static void	set_pixel(unsigned int *data, int *cr)
{
	if (cr[4] > cr[5])
		cr[4] -= 0x505;
	else if (cr[4] < cr[5])
		cr[4] += 0x505;
	if (cr[1] < HIGHT - 1 && cr[0] < WIDTH - 1)
		data[cr[1] * WIDTH + cr[0]] = cr[4];
}

static void	init_delta(int *delta, t_point a, t_point b)
{
	delta[0] = mabs((int)b.x - (int)a.x);
	delta[1] = mabs((int)b.y - (int)a.y);
	delta[2] = a.x < b.x ? 1 : -1;
	delta[3] = a.y < b.y ? 1 : -1;
	delta[4] = delta[0] - delta[1];
}

static void	init_coords(int *coords, t_point a, t_point b)
{
	coords[0] = a.x;
	coords[1] = a.y;
	coords[2] = b.x;
	coords[3] = b.y;
	coords[4] = a.clr;
	coords[5] = b.clr;
}

/*
**	coords[4] : a.x | a.y | b.x | b.y | clr
*/

void		draw_line(unsigned int *data, t_point a, t_point b)
{
	int				delta[6];
	int				cr[6];

	init_delta(delta, a, b);
	init_coords(cr, a, b);
	if (cr[2] >= 0 && cr[3] >= 0 && cr[2] < WIDTH && cr[3] < HIGHT)
		set_pixel(data, cr);
	while ((cr[0] != cr[2] || cr[1] != cr[3]) && cr[0] < WIDTH && cr[1] < HIGHT
			&& cr[0] >= 0 && cr[1] >= 0)
	{
		if (cr[0] >= 0 && cr[1] >= 0)
			set_pixel(data, cr);
		delta[5] = delta[4] * 2;
		if (delta[5] > -delta[1])
		{
			delta[4] -= delta[1];
			cr[0] += delta[2];
		}
		if (delta[5] < delta[0])
		{
			delta[4] += delta[0];
			cr[1] += delta[3];
		}
	}
}
