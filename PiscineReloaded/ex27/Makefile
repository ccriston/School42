# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccriston <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 11:21:33 by ccriston          #+#    #+#              #
#    Updated: 2019/04/03 14:17:08 by ccriston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

FLAGS = -Wall -Wextra -Werror

SRC = read.c

.PHONY: all clean fclean re

all:
	gcc -o $(NAME) $(FLAGS) $(SRC)
	
clean:
	/bin/rm -f *.o

fclean: clean 
	/bin/rm -f $(NAME)

re: fclean all
