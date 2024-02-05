# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:38:30 by cspreafi          #+#    #+#              #
#    Updated: 2023/04/18 13:42:09 by cspreafi         ###   ########.fr        #
#                                                                              #
# *****************************************************************************#

COMPILE = gcc
CFLAG = -Wall -Werror -Wextra
SRC = get_next_line.c \
		get_next_line_utils.c

NAME = get_next_line.a
OBJ = $(src:.c=.o)
CLEANCMD = rm -rf *.o
FCLEANCMD = rm -rf *.a


#compile all ft at once and put ion a library
$(NAME):$(OBJ)
	$(COMPILE) $(CFLAG) -c $(SRC)
	ar rcs get_next_line.a *.o

all:$(NAME)

#to compile only one ft at the time
%.o:%.c
	$(COMPILE) $(CFLAG) -c $< -o $@

#clear all lib file
clean:
	$(CLEANCMD)

#clear all .o file
fclean: clean
	$(FCLEANCMD)

re: fclean all
