# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 16:24:59 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/10 19:00:32 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR 	= ${ROOT}/includes
BUILD_DIR		= ${ROOT}/.build

SRC			= ${wildcard ${SRCS_DIR}/*.c}
OBJ			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRC:.c=.o}}
CHMEM_OBJ	= ${OBJ:.o=_memcheck.o}

CC					 = gcc
CFLAGS				 = -Wall -Wextra -Werror
memcheck: CFLAGS	+= -D MEMCHECK

NAME			= ${ROOT}/libft.a
EXPORT_INCLUDE	= ${ROOT}/libft.h
CHMEM_LIB		= ${ROOT}/libft_memcheck.a


.PHONY: all clean fclean re memcheck norm


all: ${NAME} ${EXPORT_INCLUDE}

${NAME}: ${OBJ} | ${EXPORT_LIB_DIR}
	@ar rc $@ $^
	@echo "Archive created at $@."

clean:
	@rm -rf ${BUILD_DIR}
	@echo "Build folder deleted. (Libft)"

fclean: clean
	@rm -rf ${NAME}
	@echo "${NAME} deleted."
	@rm -rf ${CHMEM_LIB}
	@echo "${CHMEM_LIB} deleted."
	@rm -rf ${EXPORT_INCLUDE}
	@echo "${EXPORT_INCLUDE} deleted."

re: fclean all



memcheck: ${CHMEM_LIB} ${EXPORT_INCLUDE}

${CHMEM_LIB}: ${CHMEM_OBJ} | ${EXPORT_LIB_DIR}
	@ar rc $@ $^
	@echo "Archive created at $@."



norm:
	@norminette ${SRCS_DIR} ${INCLUDES_DIR}



#All targets
${BUILD_DIR}/%_memcheck.o ${BUILD_DIR}/%.o: ${SRCS_DIR}/%.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

${ROOT}/%.h: ${INCLUDES_DIR}/%.h | ${EXPORT_INCLUDE_DIR}
	@cp $< $@
	@echo "Include file copied at $@."


#folders
${BUILD_DIR}:
	@mkdir -p $@
	@echo "Folder $@ created."

