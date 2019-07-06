/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:53:07 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 23:11:55 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			move_mid(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			map->points[i][j].x -= map->mid_x;
			map->points[i][j].y -= map->mid_y;
		}
	}
}

void			move_back(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			map->points[i][j].x += map->mid_x;
			map->points[i][j].y += map->mid_y;
		}
	}
}

void			move_center(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			map->points[i][j].x -= map->mid_x;
			map->points[i][j].y -= map->mid_y;
			map->points[i][j].x += WIDTH / 2;
			map->points[i][j].y += HIGHT / 2;
		}
	}
	map->mid_x = WIDTH / 2;
	map->mid_y = HIGHT / 2;
}
