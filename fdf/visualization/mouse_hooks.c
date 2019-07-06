/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:21:52 by jschille          #+#    #+#             */
/*   Updated: 2019/07/04 10:40:18 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			mouse_move(int x, int y, t_mlx *img)
{
	if (img->pres_m == 1)
	{
		destroy(img);
		move_img(img->map, x - img->pres_x, y - img->pres_y);
		img->pres_y = y;
		img->pres_x = x;
		re_draw(img);
	}
	return (0);
}

int			mouse_pres(int btn, int x, int y, t_mlx *img)
{
	if (btn == 1)
	{
		img->pres_m = 1;
		img->pres_x = x;
		img->pres_y = y;
	}
	if (btn == 4)
	{
		destroy(img);
		ft_pluscale(img->map);
		re_draw(img);
	}
	if (btn == 5)
	{
		destroy(img);
		ft_minscale(img->map);
		re_draw(img);
	}
	return (0);
}

int			mouse_releas(int btn, int x, int y, t_mlx *img)
{
	x = y;
	if (btn == 1)
		img->pres_m = 0;
	return (0);
}
