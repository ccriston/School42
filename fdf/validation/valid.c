/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:55:11 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/03 22:21:16 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void		ft_name(char *av, t_map *fdf)
{
	int i;
	int k;
	int l;

	i = 0;
	k = 0;
	while (av[i] != '\0')
	{
		k++;
		i++;
		if (av[i] == '/')
			k = 0;
	}
	if (!(fdf->name = (char *)ft_memalloc(sizeof(char) * (k))))
		return ;
	i = i - k + 1;
	l = 0;
	while (av[i] != '\0')
	{
		fdf->name[l] = av[i];
		i++;
		l++;
	}
}

static void		ft_counthw(char *av, t_map *fdf)
{
	char	*line;
	int		i;
	int		a;
	int		fd;

	a = 0;
	fd = open(av, O_RDONLY);
	if (fd < 3)
		ft_error(0, NULL, fdf);
	while (get_next_line(fd, &line) == 1)
	{
		fdf->h++;
		i = -1;
		fdf->w = 0;
		while (line[++i] != '\0')
			if (line[i] == ' ' && line[i + 1] != '\0' && line[i + 1] != ' ')
				fdf->w++;
		if (a == 0 && fdf->h == 1)
			a = fdf->w;
		else if (a != fdf->w || fdf->w == 0)
			ft_error(2, NULL, fdf);
		free(line);
	}
	close(fd);
}

void			ft_valid(char *av, t_map *fdf)
{
	char	*line;
	int		i;
	int		fd;

	fdf->h = 0;
	ft_counthw(av, fdf);
	fdf->w++;
	fd = open(av, O_RDONLY);
	if (!(fdf->points = (t_point **)ft_memalloc(sizeof(t_point) *
	(fdf->h))) || fd < 3)
		ft_error(0, NULL, fdf);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(fdf->points[i] = ft_mkint(line, fdf->w - 1, i)))
			ft_error(2, NULL, fdf);
		i++;
		free(line);
	}
	ft_name(av, fdf);
	fdf->scale = SCALE;
}
