##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## This makefile compiles our sources files
##

NAME			=	my_sokoban

SRC			=	./src/sokoban.c \
				./src/list.c \
				./src/map_utils.c \
				./src/move.c \
				./src/utils.c \
				./src/utils_list.c \
				./src/free_all.c \
				./src/game_loop.c \

OBJ			=	$(SRC:.c=.o)

FLAGS	=			-lncurses -L./lib/my -lmy -I./include/ -lm

CFLAGS	=			-Wunused-parameter -Wall -W -Wextra -pedantic

all:	$(NAME)

valgrind:
	valgrind --leak-check=yes --show-reachable=yes -v ./$(NAME) map.txt

search:
	grep "printf" $(SRC)

%.o:	%.c
	gcc -o $@ -c $< $(FLAGS) $(CFLAGS)

wc:
	wc  	$(SRC)

$(NAME):	$(OBJ)
	make -C./lib/my/
	gcc $(OBJ) -o $(NAME) $(FLAGS) $(CFLAGS)

re:	fclean all

clean:
	rm -f $(OBJ) *~ \#*\# \

fclean:	clean
	make fclean -C./lib/my
	rm -f $(NAME)
