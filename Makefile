##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## makefle
##

SRC	=	openf.c\
		my_str_to_word_array.c\
		sokoban.c\
		lib.c\
		lib2.c\
		deplacement.c\
		box.c\
		if.c\

NAME	=	my_sokoban

INCLUDE	=	-I include/

all:	$(NAME)

$(NAME):
	gcc -g -lncurses -o $(NAME) $(SRC)
	make clean

clean:
	find . -type f -name "*#" -a -name "#*" -delete -o -name "*~" -delete

fclean: clean
	rm -rf $(NAME)

re: fclean all
