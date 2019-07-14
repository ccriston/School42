/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:22:15 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/14 12:53:22 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include "libft/libft.h"
# define WIDTH	1000
# define HIGHT	1000

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				alpha;
	char			av;
	int				stop;
	int				press;
	long double		minr;
	long double		maxr;
	long double		mini;
	long double		maxi;
	long double		zr;
	long double		zi;
	long double		cr;
	long double		ci;
	int				maxiter;
	unsigned int	clr;
}					t_mlx;

void				ft_initmlx(t_mlx *mlx);
t_mlx				*ft_initfr(t_mlx *mlx);
t_mlx				*ft_initsize(t_mlx *mlx);
void				ft_error(int a);
void				hooker(t_mlx *mlx);
int					ft_close(t_mlx *mlx);
int					key_press(int keycode, t_mlx *img);
void				re_draw(t_mlx *img);
void				destroy(t_mlx *img);
void				set_pixel(unsigned int *data, double x,
					double y, unsigned int clr);

int					mouse_pres(int btn, int x, int y, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_releas(int btn, int x, int y, t_mlx *mlx);
void				change_mlx(t_mlx *mlx, int x, int y);

void				ft_pluscale(t_mlx *mlx);
void				ft_minscale(t_mlx *mlx);
void				ft_move(t_mlx *mlx, int x, int y);
void				key_move(int keycode, t_mlx *mlx);

t_mlx				*ft_comfr(t_mlx *mlx);
unsigned int		ft_jul(t_mlx *mlx, double y, double x);
unsigned int		ft_man(t_mlx *mlx, double y, double x);
unsigned int		ft_bs(t_mlx *mlx, double y, double x);

#endif
