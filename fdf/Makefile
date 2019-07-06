NAME = fdf

FLAGS = gcc -Wall -Werror

SRC = draw/draw_line.c draw/move.c draw/rotate.c draw/scale.c draw/tracer.c \
	draw/centring.c \
	validation/convert.c validation/valid.c validation/error.c \
	visualization/create_data.c visualization/hooker.c visualization/mouse_hooks.c\
	main.c

OBJECTS = draw_line.o move.o rotate.o scale.o tracer.o centring.o \
	convert.o valid.o error.o \
	create_data.o hooker.o mouse_hooks.o\
	main.o

all: $(NAME)

$(NAME) : $(OBJECTS)
		@make -C include/libft re
		@$(FLAGS) $(OBJECTS) -I include -L include/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJECTS) : $(SRC)
		@$(FLAGS) -c $(SRC) -I include

clean: 
		@rm -rf $(OBJECTS)
		@make -C ./include/libft clean

fclean: clean
		@rm -f $(NAME)
		@make -C ./include/libft fclean

re: fclean all

.PHONY: clean all fclean re
