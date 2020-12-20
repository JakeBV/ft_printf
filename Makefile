NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_parser.c \
              ft_printf.c \
              ft_typing.c \
              ft_typing_char.c \
              ft_typing_string.c \
			  ft_typing_digit.c \
			  ft_utils.c ft_typing_hex.c

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -I. -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

all: ${NAME}

.PHONY: all clean fclean re
