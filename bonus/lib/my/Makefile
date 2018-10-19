##
## Makefile for libcsfml in /home\benoit.lormeau\delivery\...\
##
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.eu>
##
## Started on  Fri Oct 18 16:52:27 2016 Benoit Lormeau
## Last update Sat Nov 26 00:20:03 2016 Benoit Lormeau
##

CFLAGS	+=	-I../../include/

SRC	=	my_atoi.c		\
		my_nbrlen.c		\
		my_map.c		\
		my_swap.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
