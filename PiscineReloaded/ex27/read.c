/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:27:09 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/03 13:28:22 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 2048

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else if (ac < 2)
		write(1, "File name missing.\n", 19);
	else
	{
		fd = open(av[1], O_RDONLY);
		while ((ret = read(fd, buf, BUF_SIZE)) > 0)
		{
			write(1, buf, ret);
		}
		close(fd);
	}
	return (0);
}
