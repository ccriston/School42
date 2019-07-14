/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:21:52 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 15:21:53 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		destroy(t_mlx *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_new_image(img->mlx_ptr, WIDTH, HIGHT);
	img->img_data = (unsigned int*)mlx_get_data_addr(img->img_ptr,
					&img->bpp, &img->size_line, &img->alpha);
}

void		re_draw(t_mlx *img)
{
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
}

void		ft_initmlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HIGHT, "fdf");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGHT);
	mlx->bpp = 4;
	mlx->size_line = WIDTH;
	mlx->alpha = 1;
	mlx->img_data = (unsigned int*)mlx_get_data_addr(mlx->img_ptr,
	&(mlx->bpp), &(mlx->size_line), &(mlx->alpha));
	mlx->stop = 0;
}

t_mlx		*ft_initsize(t_mlx *mlx)
{
	mlx->maxi = 2;
	mlx->mini = -2;
	mlx->maxr = 2;
	mlx->minr = -2;
	mlx->maxiter = 200;
	return (mlx);
}

t_mlx		*ft_initfr(t_mlx *mlx)
{
	ft_initsize(mlx);
	mlx->zr = 0.0;
	mlx->zi = 0.0;
	mlx->clr = 1000;
	if (mlx->av == 'm')
	{
		mlx->cr = 0.0;
		mlx->ci = 0.0;
	}
	if (mlx->av == 'j')
	{
		mlx->cr = 0.5;
		mlx->ci = 0.5;
	}
	if (mlx->av == 'b')
	{
		mlx->maxi = 2;
		mlx->mini = -2;
		mlx->maxr = 2;
		mlx->minr = -2.5;
		mlx->zr = 0;
		mlx->zi = 0;
	}
	return (mlx);
}
