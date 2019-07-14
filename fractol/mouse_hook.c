/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:21:58 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 15:21:59 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change_mlx(t_mlx *mlx, int x, int y)
{
	mlx->cr = -1 + (long double)x / ((long double)WIDTH / 2);
	mlx->ci = -1 + (long double)y / ((long double)HIGHT / 2);
}

int			mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->stop == 0)
	{
		destroy(mlx);
		change_mlx(mlx, x, y);
		ft_comfr(mlx);
		re_draw(mlx);
	}
	return (0);
}

int			mouse_pres(int btn, int x, int y, t_mlx *mlx)
{
	destroy(mlx);
	if (btn == 1)
	{
		ft_move(mlx, x, y);
		ft_pluscale(mlx);
		mlx->press = 1;
	}
	if (btn == 2 && mlx->stop == 0)
		mlx->stop = 1;
	else if (btn == 2 && mlx->stop == 1)
		mlx->stop = 0;
	if (btn == 4 || btn == 5)
	{
		if (mlx->press == 1)
		{
			mlx->press = 0;
			ft_initsize(mlx);
		}
		btn == 4 ? ft_minscale(mlx) : ft_pluscale(mlx);
	}
	ft_comfr(mlx);
	re_draw(mlx);
	return (0);
}
