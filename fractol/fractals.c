/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:21:21 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 16:04:34 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx			*ft_comfr(t_mlx *mlx)
{
	double			x;
	double			y;
	unsigned int	i;

	y = -1;
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = (mlx->av == 'j') ? ft_jul(mlx, y, x) : 0;
			if (mlx->av == 'm')
				i = ft_man(mlx, y, x);
			if (mlx->av == 'b')
				i = ft_bs(mlx, y, x);
			if (i == 200)
				set_pixel(mlx->img_data, x, y, 0);
			else if (i == 0)
				set_pixel(mlx->img_data, x, y, 0x404040);
			else
				set_pixel(mlx->img_data, x, y, i * mlx->clr);
		}
	}
	return (mlx);
}

unsigned int	ft_man(t_mlx *mlx, double y, double x)
{
	unsigned int	i;
	double			sq;
	double			temp;

	if (mlx->maxr != mlx->minr)
		mlx->cr = mlx->minr + x / (WIDTH / (mlx->maxr - mlx->minr));
	if (mlx->maxi != mlx->mini)
		mlx->ci = mlx->mini + y / (HIGHT / (mlx->maxi - mlx->mini));
	mlx->zr = 0;
	mlx->zi = 0;
	sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
	i = 0;
	while (sq < 4.0 && i < mlx->maxiter)
	{
		temp = mlx->zr * mlx->zr - mlx->zi * mlx->zi + mlx->cr;
		mlx->zi = 2 * mlx->zr * mlx->zi + mlx->ci;
		mlx->zr = temp;
		sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
		i++;
	}
	return (i);
}

unsigned int	ft_jul(t_mlx *mlx, double y, double x)
{
	unsigned int	i;
	double			sq;
	double			temp;

	if (mlx->maxr != mlx->minr)
		mlx->zr = mlx->minr + x / (WIDTH / (mlx->maxr - mlx->minr));
	if (mlx->maxi != mlx->mini)
		mlx->zi = mlx->mini + y / (HIGHT / (mlx->maxi - mlx->mini));
	sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
	i = 0;
	while (sq < 4 && i < mlx->maxiter)
	{
		temp = mlx->zr * mlx->zr - mlx->zi * mlx->zi + mlx->cr;
		mlx->zi = 2 * mlx->zr * mlx->zi + mlx->ci;
		mlx->zr = temp;
		sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
		i++;
	}
	return (i);
}

unsigned int	ft_bs(t_mlx *mlx, double y, double x)
{
	unsigned int	i;
	double			sq;
	double			temp;

	if (mlx->maxr != mlx->minr)
		mlx->cr = mlx->minr + x / (WIDTH / (mlx->maxr - mlx->minr));
	if (mlx->maxi != mlx->mini)
		mlx->ci = mlx->mini + y / (HIGHT / (mlx->maxi - mlx->mini));
	mlx->zr = 0;
	mlx->zi = 0;
	sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
	i = 0;
	while (sq < 4 && i < mlx->maxiter)
	{
		temp = mlx->zr * mlx->zr - mlx->zi * mlx->zi + mlx->cr;
		mlx->zi = fabsl(2 * mlx->zr * mlx->zi) + mlx->ci;
		mlx->zr = fabsl(temp);
		sq = mlx->zr * mlx->zr + mlx->zi * mlx->zi;
		i++;
	}
	return (i);
}
