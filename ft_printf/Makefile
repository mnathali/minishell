CC		=		clang
CFLAGS	=		-Wall -Werror -Wextra

NAME	=		libftprintf.a

SRC	=			ft_putnbr_base.c	\
				ft_calloc.c			\
				ft_isdigit.c		\
				ft_memmove.c		\
				ft_putnbr_fd.c		\
				ft_strdup.c			\
				ft_strlcpy.c		\
				ft_strnstr.c		\
				ft_tolower.c		\
				ft_isalnum.c		\
				ft_isprint.c		\
				ft_memchr.c			\
				ft_memset.c			\
				ft_putstr_fd.c		\
				ft_striteri.c		\
				ft_strlen.c			\
				ft_strrchr.c		\
				ft_toupper.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_itoa.c			\
				ft_memcmp.c			\
				ft_putchar_fd.c		\
				ft_split.c			\
				ft_strjoin.c		\
				ft_strmapi.c		\
				ft_strtrim.c		\
				ft_bzero.c			\
				ft_isascii.c		\
				ft_memcpy.c			\
				ft_putendl_fd.c		\
				ft_strchr.c			\
				ft_strlcat.c		\
				ft_strncmp.c		\
				ft_substr.c			\
				ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstiter.c		\
				ft_lstmap.c			\
				ft_strcmp.c			\
				array_clear.c		\
				ft_printf.c			\
				ft_array_size.c		\
				ft_lst_getbyid.c	\
				ft_isspace.c

OBJ_PATH	=	objects
SRC_PATH	=	src
INC_PATH	=	include

OBJ			=	${SRC:%.c=${OBJ_PATH}/%.o}


HEADERS	=		ft_printf.h				\
				libft.h				

HEAD_DEP	=	${HEADERS:%.h=${INC_PATH}/%.h}

.PHONY : all clean fclean re

all : ${NAME}

${OBJ_PATH}/%.o : ${SRC_PATH}/%.c ${HEAD_DEP} | ${OBJ_PATH}
	${CC} ${CFLAGS} -c $< -o $@ -I${INC_PATH}

${OBJ_PATH}:
	mkdir ${OBJ_PATH}

${NAME} : ${OBJ}
	ar rcs ${NAME} $?
	@echo "The library has been compiled."

clean :
	@rm -rf ${OBJ_PATH}

fclean : clean
	@rm -f ${NAME}

re : fclean all
