/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:43:58 by jschille          #+#    #+#             */
/*   Updated: 2019/07/04 11:25:16 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_up(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_y < 0)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].y -= MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_y -= MOVE;
}

void	ft_down(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_y > HIGHT)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].y += MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_y += MOVE;
}

void	ft_left(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_x < 0)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x -= MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_x -= MOVE;
}

void	ft_right(t_map *fdf)
{
	int x;
	int y;

	if (fdf->mid_x > WIDTH)
		return ;
	y = 0;
	while (y < fdf->h)
	{
		x = 0;
		while (x < fdf->w)
		{
			fdf->points[y][x].x += MOVE;
			x++;
		}
		y++;
	}
	fdf->mid_x += MOVE;
}

void	move_img(t_map *fdf, int x, int y)
{
	int j;
	int i;

	if (check_md(fdf, x, y))
		return ;
	i = 0;
	while (i < fdf->h)
	{
		j = 0;
		while (j < fdf->w)
		{
			fdf->points[i][j].x += x;
			fdf->points[i][j].y += y;
			j++;
		}
		i++;
	}
	fdf->mid_x += x;
	fdf->mid_y += y;
}
