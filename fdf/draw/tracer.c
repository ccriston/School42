/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:06:37 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 22:23:33 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_next(unsigned int *data, t_map *map, int i, int j)
{
	int		end_w;
	int		end_h;

	end_w = map->w - 1;
	end_h = map->h - 1;
	if (j < end_w)
		draw_line(data, map->points[i][j], map->points[i][j + 1]);
	if (i < end_h)
		draw_line(data, map->points[i][j], map->points[i + 1][j]);
}

static int		draw_previous(unsigned int *data, t_map *map, int i, int j)
{
	int		end_w;
	int		end_h;

	end_w = map->w - 1;
	end_h = map->h - 1;
	if (j != 0)
		draw_line(data, map->points[i][j], map->points[i][j - 1]);
	if (i != 0)
		draw_line(data, map->points[i][j], map->points[i - 1][j]);
	if (j < end_w)
		draw_line(data, map->points[i][j], map->points[i][j + 1]);
	if (i < end_h)
		draw_line(data, map->points[i][j], map->points[i + 1][j]);
	return (1);
}

void			trace_point(t_map *map, t_mlx *mlx)
{
	int		i;
	int		j;
	int		f;

	i = -1;
	f = 1;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
		{
			if ((int)map->points[i][j].x < 0 || (int)map->points[i][j].y < 0)
			{
				f = 0;
				continue ;
			}
			else if (map->points[i][j].x > WIDTH || map->points[i][j].y > HIGHT)
				continue ;
			else if (f == 1)
				draw_next(mlx->img_data, map, i, j);
			else
				f = draw_previous(mlx->img_data, map, i, j);
		}
	}
}
