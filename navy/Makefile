##
## EPITECH PROJECT, 2020
## Makefile du main
## File description:
## le make lance tout le projet
##

SRC	=	main.c\
		./sources/error.c\
		./sources/error2.c\
		./sources/usage.c\
		./sources/connection.c\
		./sources/send_connection.c\
		./sources/received_connection.c\
		./sources/map.c\
		./sources/map2.c


OBJ	=	$(SRC:.c=.o)

NAME	=	navy

all:
		make -C lib/my
		gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy

valgrind:
		make -C lib/my
		gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -g3

clean:
		make -C lib/my clean

fclean:
		make -C lib/my fclean
		rm $(NAME)

re:		fclean all
