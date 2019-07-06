# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschille <jschille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 13:22:25 by ccriston          #+#    #+#              #
#    Updated: 2019/07/03 14:16:19 by ccriston         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS= ft_isdigit.c ft_lstmap.c ft_memset.c ft_strcat.c ft_striteri.c \
	  ft_strnequ.c ft_tolower.c ft_islower.c ft_lstnew.c ft_putchar.c \
	  ft_strchr.c ft_strjoin.c ft_strnew.c ft_toupper.c ft_atoi.c ft_isprint.c \
	  ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c ft_strnstr.c \
	  ft_bzero.c ft_isupper.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c \
	  ft_strrchr.c ft_countwords.c ft_itoa.c ft_memchr.c ft_putendl_fd.c \
	  ft_strcpy.c ft_strmap.c ft_strrev.c ft_firstword.c ft_lstadd.c \
	  ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strsplit.c \
	  ft_isalnum.c ft_lstdel.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c \
	  ft_strncat.c ft_strstr.c ft_isalpha.c ft_lstdelone.c ft_memdel.c \
	  ft_putstr.c ft_strequ.c ft_strncmp.c ft_strsub.c ft_isascii.c	ft_strtrim.c \
	  ft_lstiter.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c \
		get_next_line.c ft_sqrt.c

OBJECTS=ft_isdigit.o ft_lstmap.o ft_memset.o ft_strcat.o ft_striteri.o \
		ft_strnequ.o ft_tolower.o ft_islower.o ft_lstnew.o ft_putchar.o \
		ft_strchr.o ft_strjoin.o ft_strnew.o ft_toupper.o ft_atoi.o \
		ft_isprint.o ft_memalloc.o ft_putchar_fd.o ft_strclr.o ft_strlcat.o \
		ft_strnstr.o ft_bzero.o ft_isupper.o ft_memccpy.o ft_putendl.o \
		ft_strcmp.o ft_strlen.o ft_strrchr.o ft_countwords.o ft_itoa.o \
		ft_memchr.o ft_putendl_fd.o ft_strcpy.o ft_strmap.o ft_strrev.o \
		ft_firstword.o ft_lstadd.o ft_memcmp.o ft_putnbr.o ft_strdel.o \
		ft_strmapi.o ft_strsplit.o ft_isalnum.o ft_lstdel.o ft_memcpy.o \
		ft_putnbr_fd.o ft_strdup.o ft_strncat.o ft_strstr.o ft_isalpha.o \
		ft_lstdelone.o ft_memdel.o ft_putstr.o ft_strequ.o ft_strncmp.o \
		ft_strsub.o ft_isascii.o ft_strtrim.o ft_lstiter.o ft_memmove.o \
		ft_putstr_fd.o ft_striter.o ft_strncpy.o get_next_line.o ft_sqrt.o

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS) -g
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
