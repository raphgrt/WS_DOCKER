##
## EPITECH PROJECT, 2023
## My str_dup.h
## File description:
## my_MakeFile
##

TARGET		=	my_sokoban
CC			=	gcc
CXXFLAGS	=	-Wall -Wextra -Werror
LDFLAGS		=	-lncurses
OBJS 		= 	${SRCS:.c=.o}

SRCS 	=	src/main.c			src/map.c		\
			src/map_handler.c	src/terminal.c	\
			src/game.c							\

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CXXFLAGS} ${OBJS} ${LDFLAGS} -o ${TARGET}

clean:
	rm -fr ${OBJS}

fclean: clean
	rm -fr ${TARGET}

re: fclean all

.PHONY: clean fclean re
