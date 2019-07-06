/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:54:02 by jschille          #+#    #+#             */
/*   Updated: 2019/07/04 11:26:39 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_help(t_mlx *img)
{
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 200,
	10, 0xFFFFFF, "Manual");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	50, 0xFFFFFF, "Rotate around X    W - S");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	75, 0xFFFFFF, "Rotate around Y    A - D");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	100, 0xFFFFFF, "Rotate around Z    Q - E");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	125, 0xFFFFFF, "Plus scale         P");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	150, 0xFFFFFF, "Minus scale        O");
	mlx_string_put(img->mlx_ptr, img->win_ptr, WIDTH - 300,
	175, 0xFFFFFF, "Move               arrows");
}

static void	init_data(t_mlx *mlx, t_map *map)
{
	mlx->bpp = 4;
	mlx->size_line = WIDTH;
	mlx->alpha = 1;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HIGHT, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGHT);
	mlx->img_data = (unsigned int*)mlx_get_data_addr(mlx->img_ptr,
					&(mlx->bpp), &(mlx->size_line), &(mlx->alpha));
	mlx->map = map;
}

void		create_loop(t_map *map)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_error(0, mlx, map);
	init_data(mlx, map);
	trace_point(map, mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	hooker(mlx);
	ft_help(mlx);
	mlx_loop(mlx->mlx_ptr);
	ft_free(mlx->map);
	ft_free(map);
	ft_memdel((void **)&(mlx));
}

void		re_draw(t_mlx *img)
{
	trace_point(img->map, img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	ft_help(img);
}
