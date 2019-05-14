/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccriston <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:11:11 by ccriston          #+#    #+#             */
/*   Updated: 2019/04/22 12:37:54 by ccriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 32

typedef	struct	s_getlist
{
	int				fd;
	char			*content;
	ssize_t			ret;
	struct s_list	*next;
}				t_getlist;

int				get_next_line(const int fd, char **line);

#endif
