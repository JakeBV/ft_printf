NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SRCS		= ft_atoi.c ft_strchr.c ft_strlen.c

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
