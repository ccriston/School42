/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:43:39 by jschille          #+#    #+#             */
/*   Updated: 2019/07/04 13:57:12 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# define WIDTH	1920
# define HIGHT	1080
# define SCALE	2
# define MOVE	10
# define DIST	100

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	unsigned int	clr;
}					t_point;

typedef struct		s_map
{
	char			*name;
	t_point			**points;
	int				w;
	int				h;
	unsigned int	scale;
	int				mid_x;
	int				mid_y;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_map			*map;
	unsigned int	*img_data;
	int				bpp;
	int				size_line;
	int				alpha;
	int				pres_m;
	int				pres_x;
	int				pres_y;
}					t_mlx;

/*
**Module 1 validation
*/

t_point				*ft_mkint(char *str, int n, int y);
void				ft_valid(char *av, t_map *map);
void				ft_error(int a, t_mlx *mlx, t_map *fdf);
void				ft_free(t_map *fdf);
int					ft_close(t_mlx *mlx);

/*
**Module 2 draw
*/

void				trace_point(t_map *map, t_mlx *mlx);
void				draw_line(unsigned int *data, t_point a, t_point b);
void				rotate_x(t_map *map, double angle, t_point **points);
void				rotate_y(t_map *map, double angle, t_point **points);
void				rotate_z(t_map *map, double angle, t_point **points);
void				ft_up(t_map *map);
void				ft_down(t_map *map);
void				ft_left(t_map *map);
void				ft_right(t_map *map);
void				ft_minscale(t_map *fdf);
void				ft_pluscale(t_map *fdf);
void				ft_help(t_mlx *img);

void				move_center(t_map *map);
void				move_mid(t_map *map);
void				move_back(t_map *map);
void				move_img(t_map *fdf, int x, int y);

void				re_draw(t_mlx *img);
void				destroy(t_mlx *img);
int					mouse_releas(int btn, int x, int y, t_mlx *img);
int					mouse_pres(int btn, int x, int y, t_mlx *img);
int					mouse_move(int x, int y, t_mlx *img);
int					check_md(t_map *fdf, int x, int y);

/*
**Module 3 visualization
*/

void				create_loop(t_map *map);
void				hooker(t_mlx *mlx);
void				err_out(int e);

#endif
