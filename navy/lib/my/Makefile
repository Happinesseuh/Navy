##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	my_getnbr.c		\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_str_isalpha.c	\
		my_str_isnum.c	\
		my_strlen.c		\
		my_put_un_nbr.c		\
		my_strdup.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	 libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../
	mkdir -p ../../include/
	cp my.h ../../include/
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../libmy.a

re:	fclean all
	rm -f *.o
	rm -f *~
	rm *#
