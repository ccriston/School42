/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:42:09 by jschille          #+#    #+#             */
/*   Updated: 2019/07/03 23:11:07 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_out(int e)
{
	if (e == 0)
		write(1, "Error! Don't have memory\n", 25);
	if (e == 1)
		write(1, "usage: ./fdf <filename>\n", 24);
	if (e == 2)
		write(1, "Invalid map2\n", 12);
	exit(0);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		err_out(1);
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		err_out(2);
	ft_valid(argv[1], map);
	map->mid_x = (map->w - 1) * SCALE / 2;
	map->mid_y = (map->h - 1) * SCALE / 2;
	move_center(map);
	create_loop(map);
	exit(0);
}
