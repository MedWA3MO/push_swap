# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moouaamm <moouaamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 20:54:19 by moouaamm          #+#    #+#              #
#    Updated: 2023/01/28 00:14:01 by moouaamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BNS = checker

LIB = lib

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCF = index.c lis.c mag_stack.c parsing.c range_tree.c sorted.c same_half.c\
		best_mv.c join.c list_to_tab.c  repush_fromB.c main.c
OBJF = $(SRCF:.c=.o)

BNSF = bonus/index_bonus.c  bonus/parsing_bonus.c  bonus/rules_bonus.c bonus/checker_bonus.c\
		bonus/join_bonus.c  bonus/mag_stack_bonus.c   bonus/sorted_bonus.c bonus/get_next_utils_bonus.c\
		bonus/get_next_line_bonus.c

BNSO = $(BNSF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJF)
	@$(MAKE) -C $(LIB)
	@$(CC) $(CFLAGS) $(OBJF) ./lib/libft.a -o $(NAME)

%.o : %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

bonus : $(BNSO)
	@$(MAKE) -C $(LIB)
	@$(CC) $(CFLAGS) $(BNSO) ./lib/libft.a -o $(BNS)

./bonus/%_bonus.o : ./bonus/%_bonus.c ./bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(MAKE) clean -C $(LIB)
	@rm -f $(OBJF)
	@rm -f $(BNSO)

fclean : clean
	@$(MAKE) fclean -C $(LIB)
	@rm -f $(NAME)
	@rm -f $(BNS)

re : fclean all

.PHONY : all clean fclean re bonus