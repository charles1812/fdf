NAME = fdf

SRC =	fdf.c \
	libft/libft.a \
	minilibx-linux/libmlx.a \
	minilibx_linux/libmlx-Linux.a \


OBJ = ${SRC:.c=.o}

COMPILE = gcc

CFLAG = -Wall -Werror -Wextra -lmlx


#compile all ft at once and put ion a library
$(NAME):
	make all -C libft
	$(COMPILE) $(SRC) -o $(NAME)
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
