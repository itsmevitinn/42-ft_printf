SRCS	= ft_strlen.c ft_putstr.c ft_putchar.c ft_addresstohex.c

OBJS	= ${SRCS:.c=.o}

NAME	= printf.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR_RC 	= ar rc

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${AR_RC} ${NAME} ${OBJS} 

all:		$(NAME)

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

test:		all
			gcc ft_printf.c ${NAME} && ./a.out

re:		fclean all

.PHONY:		all clean fclean re