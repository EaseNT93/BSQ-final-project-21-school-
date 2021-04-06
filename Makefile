SRCS	=	src/ft_atoi.c \
			src/ft_biggest_square.c \
			src/ft_create_elem.c \
			src/ft_matrix_char.c \
			src/ft_matrix_int.c \
			src/ft_putstr.c \
			src/ft_read_console.c \
			src/ft_read_file.c \
			src/ft_strcat.c \
			main.c

OBJS	=	${SRCS:.c=.o}

NAME	=	bsq

GCC		=	gcc
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

.c.o:		
			${GCC} ${CFLAGS} -c $< -o $@ -I includes

${NAME}:	${OBJS}
			${GCC} ${CFLAGS} ${SRCS} -o ${NAME} -I includes

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
