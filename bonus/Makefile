##
## Makefile for wireframe_bootstrap in /home/benito/delivery/CGP_2016_wireframe_bootstrap
## 
## Made by Benoit Lormeau
## Login   <benoit.lormeau@epitech.net>
## 
## Started on  Mon Nov 14 18:08:58 2016 Benoit Lormeau
## Last update Thu Nov 24 14:47:22 2016 Benoit Lormeau
##

CC	=	gcc

RM	=	rm -f

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Iinclude/
CFLAGS	+=	-lc_graph_prog
CFLAGS	+=	-Llib -lmysfml -lmy -lm

SRC	=	src/main.c		\
		src/buffer.c		\
		src/perlin.c		\
		src/vertex.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wireframe

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

lib:
	cd lib/my && make
	cd lib/mysfml && make

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean lib all

gen:
	gcc -o misc/gen misc/generate_wf.c

.PHONY: all clean fclean re lib
