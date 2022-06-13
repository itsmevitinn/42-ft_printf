LIBFT_PATH = ./libft

MAKE_IN_DIRECTORY = make -C

MAKELIBFT = ${MAKE_IN_DIRECTORY} ${LIBFT_PATH}

NAME	= libftprintf.a

CPLIBFT = cp ${LIBFT_PATH}/libft.a libftprintf.a

SRCS	= ft_putstr_int.c ft_putchar_int.c ft_unsignedtohex.c ft_unsigneditoa.c ft_printf.c ft_printf_utils.c

OBJS	= ${SRCS:.c=.o}

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
			${RM} ${OBJS}
			${MAKE_IN_DIRECTORY} ${LIBFT_PATH} clean

fclean:		clean
			${RM} ${NAME} 
			${MAKE_IN_DIRECTORY} ${LIBFT_PATH} fclean

re:		fclean all

.PHONY:		all clean fclean re
