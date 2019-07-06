/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 10:55:56 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/04 13:56:05 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_close(t_mlx *mlx)
{
	if (mlx->map)
		ft_free(mlx->map);
	ft_memdel((void **)&(mlx));
	exit(0);
	return (0);
}

static unsigned int	ft_atoi16(const char *str)
{
	unsigned int	f;
	unsigned int	i;
	unsigned int	result;
	unsigned int	res;
	char			*arr;

	arr = "0123456789ABCDEF";
	f = 0;
	while ((str[f] >= '0' && str[f] <= '9') || (str[f] >= 'A' && str[f] <= 'F'))
		f++;
	i = f;
	result = 16;
	while (--i)
		result = result * 16;
	res = 0;
	while ((result = result / 16) > 0)
	{
		f = 0;
		while (arr[f] != str[i] && str[i] != '\0')
			f++;
		res = f * result + res;
		i++;
	}
	return (res);
}

static void			ft_fillcoord(int x, int y, int z, t_point *new)
{
	new->x = x * SCALE;
	new->y = y * SCALE;
	new->z = z * SCALE;
}

static int			ft_checkcolor(char *str, int i, t_point *new)
{
	int j;

	j = 0;
	if (str[i] == ',')
	{
		new->clr = ft_atoi16(str + (i + 3));
		j = 0;
		while (str[i] != ' ' && str[i] != '\0')
		{
			if (str[i] != ',' && str[i] != 'x' && (str[i] < '0' || str[i] > '9')
			&& (str[i] < 'A' || str[i] > 'F'))
				return (0);
			i++;
			j++;
		}
		if (j != 9)
			return (0);
	}
	else
		new->clr = 0xFFFFFF - new->z / SCALE * 0x808;
	return (i);
}

t_point				*ft_mkint(char *str, int n, int y)
{
	t_point		*new;
	int			i;
	int			k;

	new = (t_point *)malloc(sizeof(t_point) * (n + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0' && k <= n)
		if (str[i] == ' ')
			i++;
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			ft_fillcoord(k, y, ft_atoi(str + i), &new[k]);
			k++;
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
			if ((i = ft_checkcolor(str, i, &new[k - 1])) == 0)
				return (0);
		}
		else
			return (0);
	return (new);
}
