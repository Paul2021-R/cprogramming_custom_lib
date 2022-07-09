# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 00:30:34 by haryu             #+#    #+#              #
#    Updated: 2022/07/10 02:30:42 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= $(wildcard ./*.c)
OBJS			= $(SRCS:.c=.o)

NAME			= ryuu_io.a
CC				= gcc
RM				= rm -f
AR				= ar
ARFLAG			= rcs
LIB				= -L../42_libft/libft.a
CFLAGS			= -Wall -Wextra -Werror

.c.o:
				$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME):			$(OBJS)
				$(AR) $(ARFLAG) $@ $^

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re bonus so
