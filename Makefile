##
## Makefile for wireframe_bootstrap in /home/benito/delivery/CGP_2016_wireframe_bootstrap
## 
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.net>
## 
## Started on  Mon Nov 14 18:08:58 2016 Benoit Lormeau
## Last update Tue Nov 15 14:25:54 2016 Benoit Lormeau
##

CC	=	gcc

CFLAGS	+=	-Iinclude/
CFLAGS	+=	-lc_graph_prog
CFLAGS	+=	-lm

RM	=	rm -f

SRC	=	main.c			\
		buffer.c		\
		src/my_atoi.c		\
		src/my_nbrlen.c		\
		src/my_framebuffer.c	\
		src/my_put_pixel.c	\
		src/my_put_square.c	\
		src/my_draw_line.c	\
		src/my_convert_point.c	\
		src/my_draw_grid.c	\
		src/my_join_points.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -W -Wall -Werror -Wextra -Iinclude/ -lc_graph_prog -lm

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
