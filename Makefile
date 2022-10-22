CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address

NAME = minishell

SRC			=	minishell.c			\
				minishell_utils.c	\
				built_in_1.c		\
				mini_export.c		\
				mini_unset.c		\
				mini_cd.c			\
				shell_exit.c		\
				next_line.c			\
				create_shell.c		\
				parse_args.c		\
				parse_utils.c		\
				get_args.c			\
				get_environ.c		\
				list_utils.c		\
				expand_variables.c  \
				action_branch.c		\
				action_utils.c		\
				change_in_out.c		\
				here_doc.c			\
				change_envp.c		\
				action_utils_2.c	\
				signal_utils.c		\

FT_PRINTF_PATH	=	./ft_printf/include

OBJ_PATH	=	objects
SRC_PATH	=	src
INC_PATH	=	include

HEADERS		=	minishell.h		\

FT_PRINTF 	=	ft_printf/libftprintf.a 

HEAD_DEP	=	${HEADERS:%.h=${INC_PATH}/%.h}

OBJ			=	${SRC:%.c=${OBJ_PATH}/%.o}

.PHONY	:	all re clean fclean ${FT_PRINTF}

all : ${NAME}

ifneq ($(shell ${MAKE} -q -C ft_printf/ ; echo $$? ), 0)
${NAME} : ${FT_PRINTF}
endif

${FT_PRINTF}:
	@echo "Making the library."
	${MAKE} -j -s -C ft_printf/

${OBJ_PATH}:
	@mkdir ${OBJ_PATH}

${OBJ_PATH}/%.o : ${SRC_PATH}/%.c ${HEAD_DEP} | ${OBJ_PATH}
	${CC} ${CFLAGS} -o $@ -c $< -I${INC_PATH} -I${FT_PRINTF_PATH}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} -o $@  $^ ${FT_PRINTF} -lreadline
	@echo "✅ Your ${NAME} is ready to fly."

clean :
	@rm -rf ${OBJ_PATH}
	@echo "Making the project nice and clean."

fclean : clean
	@rm -f ${NAME}
	@echo "The executable has got to go..."

re:
	@echo "Rebuilding..."
	${MAKE} fclean all