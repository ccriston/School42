NAME = fractol

FLAGS = gcc -Wall -Werror

SRC = main.c hook.c mlx.c mouse_hook.c scale.c fractals.c

OBJECTS = main.o hook.o mlx.o mouse_hook.o scale.o fractals.o

all: $(NAME)

$(NAME) : $(OBJECTS)
		@make -C include/libft re
		@$(FLAGS) $(OBJECTS) -I include/fracrol.h -L include/libft -lft -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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
