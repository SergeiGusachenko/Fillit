NAME = fillit
SRCS = 	main.c\
		utils.c\
		input_clean.c\
		input_clean_row.c\
		input_clean_column.c\
		input_validate.c\
		input_validate_map.c\
		input_validate_tetrominoes.c\
		map_add.c\
		map_size.c\
		map_error.c\
		map_create.c\
		map_display.c\
		map_algorithm.c\

INCLUDES = -I fillit.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
