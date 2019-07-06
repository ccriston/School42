/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <ccriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:51:58 by ccriston          #+#    #+#             */
/*   Updated: 2019/07/03 10:51:49 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>

static int		ft_shortgnl(char **res, char **line, int fd)
{
	char	*str;
	size_t	i;

	i = 0;
	while (res[fd][i] != '\n' && res[fd][i] != '\0')
		i++;
	if (res[fd][i] == '\n')
	{
		*line = ft_strsub(res[fd], 0, i);
		str = ft_strdup(res[fd] + i + 1);
		free(res[fd]);
		res[fd] = str;
		if (res[fd][0] == '\0')
			ft_strdel(&res[fd]);
	}
	else if (res[fd][i] == '\0')
	{
		*line = ft_strdup(res[fd]);
		ft_strdel(&res[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*res[15000];
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, buf, 0) > 0 || fd > 15000)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (res[fd] == NULL)
			res[fd] = ft_strnew(1);
		str = ft_strjoin(res[fd], buf);
		free(res[fd]);
		res[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && res[fd] == NULL)
		return (0);
	return (ft_shortgnl(res, line, fd));
}
