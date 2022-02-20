# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 10:14:22 by abouchfa          #+#    #+#              #
#    Updated: 2022/02/17 15:53:46 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = mandatory/push_swap.c \
		mandatory/ops1.c \
		mandatory/ops2.c \
		mandatory/ops3.c \
		utils/partition_utils.c \
		utils/lst_utils.c \
		utils/io_utils.c \
		utils/small_sort_utils.c \
		utils/big_sort_utils.c \

BONUSFILE = bonus/checker.c \
			bonus/ops1.c \
			bonus/ops2.c \
			bonus/ops3.c \
			utils/lst_utils.c \
			utils/small_sort_utils.c \
			utils/io_utils.c \

NAME = push_swap

BONUSNAME = checker

CFLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CFILE)
	$(CFLAGS) $(CFILE) -o $(NAME)

bonus: $(BONUSNAME)

$(BONUSNAME): $(BONUSFILE)
	$(CFLAGS) $(BONUSFILE) -o $(BONUSNAME)

clean:
	rm -rf $(NAME) $(BONUSNAME)

fclean: clean

re: fclean all