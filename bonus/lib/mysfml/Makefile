##
## Makefile for libcsfml in /home\benoit.lormeau\delivery\wireframe\bonus\lib\
##
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.eu>
##
## Started on  Fri Oct 18 16:52:27 2016 Benoit Lormeau
## Last update Thu Nov 24 16:23:01 2016 Benoit Lormeau
##

CFLAGS	+=	-I../../include/
CFLAGS	+=	-lc_graph_prog -lmy

SRC	=	my_framebuffer.c		\
		my_put_pixel.c			\
		my_put_square.c			\
		my_draw_line.c			\
		my_draw_grid.c			\
		my_convert_point.c		\
		my_parallel_projection.c	\
		my_isometric_projection.c	\
		my_orthogonal_projection.c	\
		my_join_points.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmysfml.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
