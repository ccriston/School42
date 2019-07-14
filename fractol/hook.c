/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:21:33 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 15:58:40 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_clr(int keycode, t_mlx *mlx)
{
	destroy(mlx);
	if (keycode == 18)
		mlx->clr = 1000;
	if (keycode == 19)
		mlx->clr = 8192;
	if (keycode == 20)
		mlx->clr = 1000000;
	if (keycode == 21)
		mlx->clr = 10000000;
	if (keycode == 23)
		mlx->clr = 15;
	ft_comfr(mlx);
	re_draw(mlx);
}

void	key_move(int keycode, t_mlx *mlx)
{
	mlx->press = 1;
	destroy(mlx);
	if (keycode == 124)
	{
		mlx->maxr -= 0.1 * (mlx->maxr - mlx->minr);
		mlx->minr -= 0.1 * (mlx->maxr - mlx->minr);
	}
	if (keycode == 123)
	{
		mlx->maxr += 0.1 * (mlx->maxr - mlx->minr);
		mlx->minr += 0.1 * (mlx->maxr - mlx->minr);
	}
	if (keycode == 126)
	{
		mlx->maxi += 0.1 * (mlx->maxi - mlx->mini);
		mlx->mini += 0.1 * (mlx->maxi - mlx->mini);
	}
	if (keycode == 125)
	{
		mlx->maxi -= 0.1 * (mlx->maxi - mlx->mini);
		mlx->mini -= 0.1 * (mlx->maxi - mlx->mini);
	}
	ft_comfr(mlx);
	re_draw(mlx);
}

int		key_press(int kc, t_mlx *mlx)
{
	if (kc == 53)
	{
		ft_memdel((void **)&(mlx));
		exit(0);
	}
	if (kc == 18 || kc == 19 || kc == 20 || kc == 21 || kc == 23)
		key_clr(kc, mlx);
	if (kc == 123 || kc == 124 || kc == 125 || kc == 126)
		key_move(kc, mlx);
	return (0);
}

int		ft_close(t_mlx *mlx)
{
	ft_memdel((void **)&(mlx));
	exit(0);
	return (0);
}

void	hooker(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, 17, 0, ft_close, (void *)NULL);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_pres, mlx);
	if (mlx->av == 'j')
	{
		mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	}
}
