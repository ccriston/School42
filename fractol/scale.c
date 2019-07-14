/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:22:07 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 15:22:08 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pluscale(t_mlx *mlx)
{
	mlx->minr /= 2;
	mlx->maxr /= 2;
	mlx->mini /= 2;
	mlx->maxi /= 2;
}

void	ft_minscale(t_mlx *mlx)
{
	if (mlx->minr > 0)
		mlx->minr /= 2;
	else
		mlx->minr *= 2;
	if (mlx->maxr <= 0)
		mlx->maxr /= 2;
	else
		mlx->maxr *= 2;
	if (mlx->mini > 0)
		mlx->mini /= 2;
	else
		mlx->mini *= 2;
	if (mlx->maxi <= 0)
		mlx->maxi /= 2;
	else
		mlx->maxi *= 2;
}

void	ft_move(t_mlx *mlx, int x, int y)
{
	double	temp;

	temp = mlx->minr + x / (WIDTH / (mlx->maxr - mlx->minr)) + mlx->minr;
	mlx->maxr = mlx->minr + x / (WIDTH / (mlx->maxr - mlx->minr)) + mlx->maxr;
	mlx->minr = temp;
	temp = mlx->mini + y / (WIDTH / (mlx->maxi - mlx->mini)) + mlx->mini;
	mlx->maxi = mlx->mini + y / (WIDTH / (mlx->maxi - mlx->mini)) + mlx->maxi;
	mlx->mini = temp;
}
