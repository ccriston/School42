/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:46:36 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/03 22:46:30 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_pluscale(t_map *fdf)
{
	int x;
	int y;

	y = 0;
	move_mid(fdf);
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x *= fdf->scale;
			fdf->points[y][x].y *= fdf->scale;
			fdf->points[y][x].z *= fdf->scale;
			x++;
		}
		y++;
	}
	move_back(fdf);
}

void			ft_minscale(t_map *fdf)
{
	int x;
	int y;

	y = 0;
	move_mid(fdf);
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x /= fdf->scale;
			fdf->points[y][x].y /= fdf->scale;
			fdf->points[y][x].z /= fdf->scale;
			++x;
		}
		y++;
	}
	move_back(fdf);
}
