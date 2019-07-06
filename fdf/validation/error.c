/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:56:46 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/04 11:36:13 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				check_md(t_map *fdf, int x, int y)
{
	if (fdf->mid_x > WIDTH && x > 0)
		return (1);
	if (fdf->mid_x < 0 && x < 0)
		return (1);
	if (fdf->mid_y > HIGHT && y > 0)
		return (1);
	if (fdf->mid_y < 0 && y < 0)
		return (1);
	return (0);
}

void			ft_free(t_map *fdf)
{
	int y;

	y = 0;
	if (fdf)
	{
		if (fdf->points)
		{
			while (y < fdf->h && fdf->points[y])
			{
				ft_memdel((void **)&(fdf->points[y]));
				y++;
			}
			ft_memdel((void **)&fdf->points);
		}
		y = -1;
		if (fdf->points)
		{
			while (++y < fdf->h && fdf->points[y])
				ft_memdel((void **)&(fdf->points[y]));
			ft_memdel((void **)&(fdf->points));
		}
		ft_memdel((void **)&(fdf));
	}
}

void			ft_error(int a, t_mlx *mlx, t_map *fdf)
{
	if (a == 2)
	{
		write(1, "Invalid map\n", 12);
		if (fdf)
			ft_free(fdf);
		if (mlx)
		{
			ft_free(mlx->map);
			ft_memdel((void **)&(mlx));
		}
	}
	if (a == 1)
		write(1, "usage: ./fdf <filename>\n", 25);
	if (a == 0)
	{
		write(1, "error\n", 6);
		if (fdf)
			ft_free(fdf);
		if (mlx)
		{
			ft_free(mlx->map);
			ft_memdel((void **)&(mlx));
		}
	}
	exit(0);
}
