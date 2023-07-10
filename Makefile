# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 17:49:32 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/10 19:08:29 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR 	= ${ROOT}/includes
BUILD_DIR		= ${ROOT}/.build
LIBFT_DIR		= ${ROOT}/Libft

LIBS 		= ${LIBFT_DIR}/libft.a
CHMEM_LIBS	= ${LIBFT_DIR}/libft_memcheck.a

SRC			= ${wildcard ${SRCS_DIR}/*.c}
OBJ			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRC:.c=.o}}
CHMEM_OBJ	= ${OBJ:.o=_memcheck.o}

CC					 = gcc
CFLAGS				 = -Wall -Wextra -Werror
memcheck: CFLAGS	+= -D MEMCHECK
EXTERNAL_LIBS		 = -l memory_leak_detector

NAME		= ${ROOT}/push_swap

.PHONY: all clean fclean re memcheck norm


all: ${NAME}

${NAME}: ${LIBS} ${OBJ}
	@${CC} -o $@ $^
	@echo "Executable created at $@."

clean:
	@make -C ${LIBFT_DIR} clean
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted. (push_swap)"

fclean: clean
	@rm -rf ${LIBFT_DIR}/libft.a
	@echo "${LIBFT_DIR}/libft.a deleted."
	@rm -rf ${LIBFT_DIR}/libft_memcheck.a
	@echo "${LIBFT_DIR}/libft_memcheck.a deleted."
	@rm -rf ${LIBFT_DIR}/libft.h
	@echo "${LIBFT_DIR}/libft.h deleted."
	@rm -rf ${NAME}
	@echo "${NAME} deleted."

re: fclean all



memcheck: ${CHMEM_LIBS} ${CHMEM_OBJ}
	@${CC} -o ${NAME} $^ ${EXTERNAL_LIBS}
	@echo "Executable created at ${NAME}."



norm:
	@make -C ${LIBFT_DIR} norm
	@norminette ${SRCS_DIR} ${INCLUDES_DIR}



#All targets
${BUILD_DIR}/%_memcheck.o ${BUILD_DIR}/%.o: ${SRCS_DIR}/%.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR} -I${LIBFT_DIR}

${LIBFT_DIR}/libft.a:
	@make -C ${LIBFT_DIR} all

${LIBFT_DIR}/libft_memcheck.a:
	@make -C ${LIBFT_DIR} memcheck


#folders
${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."