##
## Makefile for wireframe_bootstrap in /home/benito/delivery/CGP_2016_wireframe_bootstrap
## 
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.net>
## 
## Started on  Mon Nov 14 18:08:58 2016 Benoit Lormeau
## Last update Thu Aug 31 10:52:32 2017 Benoit Lormeau
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Iinclude/
CFLAGS	+=	-lcsfml-graphics
CFLAGS	+=	-lcsfml-system
CFLAGS	+=	-lcsfml-window
CFLAGS	+=	-Llib -lmysfml -lmy -lm

SRC	=	src/main.c		\
		src/buffer.c		\
		src/perlin.c		\
		src/vertex.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

all: lib $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

lib:
	make -C lib/my
	make -C lib/mysfml

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean lib all

gen:
	gcc -o misc/gen misc/generate_wf.c

.PHONY: all clean fclean re lib