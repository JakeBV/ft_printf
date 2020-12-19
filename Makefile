NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_parser.c ft_printf.c ft_struct_worker.c ft_typing.c ft_typing_char.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	${MAKE} all -C libft/
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

all: ${NAME}

.PHONY: all clean fclean re
