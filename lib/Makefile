# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 14:59:54 by moouaamm          #+#    #+#              #
#    Updated: 2023/01/24 21:21:56 by moouaamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror
SRCF = ft_strlen.c \
	    ft_strchr.c  \
	    ft_atoi.c ft_strdup.c ft_split.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	   ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c  \

OBJF = ${SRCF:.c=.o}

all: ${NAME}

${NAME} : ${OBJF}
	@ar rc ${NAME} ${OBJF}

%.o : %.c libft.h
	@gcc ${CFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJF} ${B_OBJF}

fclean : clean
	@rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
