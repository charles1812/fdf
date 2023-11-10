NAME = fdf

SRC =	fdf.c \
	libft/libft.a \
        
OBJ = ${SRC:.c=.o}

COMPILE = gcc

CFLAG = -Wall -Werror -Wextra -g3 -I
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
#compile all ft at once and put ion a library
$(NAME):
	make all -C libft
	$(COMPILE) $(SRC) $(MLX) -g3 -lXext -lX11 -lm -o $(NAME)
#	$(COMPILE) $(CFLAG) -c $(SRC)
#	ar rcs $(NAME) *.o

all:${NAME}


#clear all lib file
clean:
	rm -f ${OBJ}
	make clean -C libft

#clear all .o file
fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all
