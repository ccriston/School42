/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:46:48 by jschille          #+#    #+#             */
/*   Updated: 2019/07/04 13:54:16 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			destroy(t_mlx *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HIGHT);
	img->img_data = (unsigned int*)mlx_get_data_addr(img->img_ptr,
					&img->bpp, &img->size_line, &img->alpha);
}

static void		ft_keyrotate(int keycode, t_mlx *img)
{
	destroy(img);
	if (keycode == 0)
		rotate_y(img->map, -0.03, img->map->points);
	if (keycode == 2)
		rotate_y(img->map, 0.03, img->map->points);
	if (keycode == 13)
		rotate_x(img->map, -0.03, img->map->points);
	if (keycode == 1)
		rotate_x(img->map, 0.03, img->map->points);
	if (keycode == 12)
		rotate_z(img->map, -0.03, img->map->points);
	if (keycode == 14)
		rotate_z(img->map, 0.03, img->map->points);
	re_draw(img);
}

static void		ft_keyscmove(int keycode, t_mlx *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HIGHT);
	img->img_data = (unsigned int*)mlx_get_data_addr(img->img_ptr,
					&img->bpp, &img->size_line, &img->alpha);
	if (keycode == 126)
		ft_up(img->map);
	if (keycode == 125)
		ft_down(img->map);
	if (keycode == 123)
		ft_left(img->map);
	if (keycode == 124)
		ft_right(img->map);
	if (keycode == 35)
	{
		ft_pluscale(img->map);
	}
	if (keycode == 31)
	{
		ft_minscale(img->map);
	}
	trace_point(img->map, img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
	ft_help(img);
}

int				key_press(int keycode, t_mlx *img)
{
	if (keycode == 53)
	{
		if (img->map)
			ft_free(img->map);
		ft_memdel((void **)&(img));
		exit(0);
	}
	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1 ||
	keycode == 12 || keycode == 14)
		ft_keyrotate(keycode, img);
	if (keycode == 126 || keycode == 125 || keycode == 124 ||
	keycode == 123 || keycode == 35 || keycode == 31)
		ft_keyscmove(keycode, img);
	return (0);
}

void			hooker(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 0, ft_close, (void *)NULL);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pres, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_releas, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
}
