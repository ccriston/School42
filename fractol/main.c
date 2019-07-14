/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:51:15 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/09 16:46:38 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(unsigned int *data, double x, double y, unsigned int clr)
{
	data[(int)y * WIDTH + (int)x] = clr;
}

void	ft_frac(char *av)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
		ft_error(0);
	if ((av[0] == 'j' || av[0] == 'm' || av[0] == 'b') && av[1] == '\0')
		mlx->av = av[0];
	else
	{
		ft_memdel((void **)&mlx);
		ft_error(1);
	}
	ft_initmlx(mlx);
	mlx = ft_initfr(mlx);
	ft_comfr(mlx);
	re_draw(mlx);
	hooker(mlx);
	mlx_loop(mlx->mlx_ptr);
}

void	ft_error(int a)
{
	if (a == 1)
	{
		write(1, "Usage: ./fractol Name_of_fractol\n", 33);
		write(1, "Available fractols: j, t, b\n", 28);
		exit(0);
	}
	if (a == 0)
	{
		write(1, "Not enough memory\n", 18);
		exit(0);
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_error(1);
	else
		ft_frac(av[1]);
	return (0);
}
