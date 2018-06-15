##
## EPITECH PROJECT, 2017
## my_printf
## File description:
## my_printf libmy builder
##

NAME	=	libmy.a

SRC_DISP=	./display_func/bin.c		\
		./display_func/octa.c		\
		./display_func/hexa.c		\
		./display_func/my_printf.c	\
		./display_func/my_put_lnbr.c	\
		./display_func/my_put_lunbr.c	\
		./display_func/my_put_nbr.c	\
		./display_func/my_put_str.c	\
		./display_func/my_put_unbr.c	\
		./display_func/my_putchar.c	\
		./display_func/my_putpointer.c	\
		./display_func/my_putstr.c	\
		./display_func/my_puterror.c	\
		./display_func/my_showstr.c

SRC_INT	=	./int_nbr_func/my_compute_power_rec.c	\
		./int_nbr_func/my_compute_square_root.c	\
		./int_nbr_func/my_find_prime_sup.c	\
		./int_nbr_func/my_get_nbr.c	\
		./int_nbr_func/my_intcpy.c	\
		./int_nbr_func/my_is_prime.c	\
		./int_nbr_func/my_isneg.c	\
		./int_nbr_func/my_sort_int_array.c	\
		./int_nbr_func/my_swap.c \
		./int_nbr_func/my_nbr_to_str.c \
		./int_nbr_func/get_nb_size.c

SRC_MEM	=	./memory_func/my_showmem.c

SRC_STR = 	./str_char_func/int_to_char.c	\
		./str_char_func/my_char_count.c	\
		./str_char_func/my_init.c	\
		./str_char_func/my_revstr.c	\
		./str_char_func/my_str_isalpha.c	\
		./str_char_func/my_str_islower.c	\
		./str_char_func/my_str_isnum.c	\
		./str_char_func/my_str_isprintable.c	\
		./str_char_func/my_str_isupper.c	\
		./str_char_func/my_str_split.c	\
		./str_char_func/my_strcapitalize.c	\
		./str_char_func/my_strcat.c	\
		./str_char_func/my_strcmp.c	\
		./str_char_func/my_strcpy.c	\
		./str_char_func/my_strlen.c	\
		./str_char_func/my_strncat.c	\
		./str_char_func/my_strncmp.c	\
		./str_char_func/my_strncpy.c	\
		./str_char_func/my_strstr.c	\
		./str_char_func/my_strupcase.c	\
		./str_char_func/my_are_equals.c \
		./str_char_func/my_is_nbr.c     \
		./str_char_func/my_realloc.c	\
		./str_char_func/set_str_to.c

SRC	=	$(SRC_MEM)	\
		$(SRC_STR)	\
		$(SRC_INT)	\
		$(SRC_DISP)	\
		./get_next_line.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME) clean

$(NAME):	$(SRC)
	gcc -c $(SRC) -I../include/
	ar -rc $(NAME) *.o

%.o:	%.c
	gcc -o $@ -c $< $(FLAGS)

re:	fclean all clean

clean:
	rm -f $(OBJ) *.o *~ \#*\#

fclean:	clean
	rm -f $(NAME)
