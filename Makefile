# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 17:49:32 by tchoquet          #+#    #+#              #
#    Updated: 2023/07/07 18:40:19 by tchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT			= .
SRCS_DIR		= ${ROOT}/sources
INCLUDES_DIR 	= ${ROOT}/includes
BUILD_DIR		= ${ROOT}/build

SRC			= ${wildcard ${SRCS_DIR}/*.c}
OBJ			= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRC:.c=.o}}
OBJ_DEBUG	= ${patsubst ${SRCS_DIR}%, ${BUILD_DIR}%, ${SRC:.c=_debug.o}}

CC						= gcc
CFLAGS					= -Wall -Wextra -Werror
alldebug: CFLAGS		= -g -D MEMCHECK
EXTERNAL_LIBS			= -l ft
alldebug: EXTERNAL_LIBS	+= -l memory_leak_detector


NAME		= ${ROOT}/push_swap
NAME_DEBUG	= ${ROOT}/Debug.out

vpath %.c ${ROOT} ${SRCS_DIR}

.PHONY: all clean fclean re debug alldebug cleandebug fcleandebug redebug norm


all: ${NAME}

${NAME}: ${OBJ}
	${CC} -o $@ $^ ${EXTERNAL_LIBS}

${BUILD_DIR}/%.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all


debug: alldebug

alldebug: ${NAME_DEBUG}

${NAME_DEBUG}: ${OBJ_DEBUG}
	${CC} -o $@ $^ ${EXTERNAL_LIBS}

${BUILD_DIR}/%_debug.o: %.c | ${BUILD_DIR}
	${CC} ${CFLAGS} -o $@ -c $< -I${INCLUDES_DIR}

cleandebug:
	rm -rf ${OBJ_DEBUG}

fcleandebug: cleandebug
	rm -rf ${NAME_DEBUG}

redebug: fcleandebug alldebug

norm:
	@norminette ${SRCS_DIR} ${INCLUDES_DIR}


#folders
${BUILD_DIR}:
	mkdir -p $@