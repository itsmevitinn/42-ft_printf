MAKELIBFT = make -C ./libft

CPLIBFT = cp ./libft/libft.a libftprintf.a

SRCS	= ft_strlen.c ft_putstr.c ft_putchar.c ft_addresstohex.c ft_itoa.c ft_unsignedtohex.c ft_strmapi.c ft_toupper.c ft_unsigneditoa.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

AR_RCS 	= ar rcs

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKELIBFT} && ${CPLIBFT} && ${AR_RCS} ${NAME} ${OBJS}  

all:		$(NAME)

clean:		
			${RM} ${OBJS} && cd ./libft && make clean

fclean:		clean
			${RM} ${NAME} && cd ./libft && make fclean

re:		fclean all

.PHONY:		all clean fclean re
