# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 10:14:22 by abouchfa          #+#    #+#              #
#    Updated: 2022/02/08 13:01:45 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = push_swap.c operations.c utils/lst_utils.c get_medium.c \
		utils/io_utils.c utils/opr_utils.c utils/sort_utils.c

NAME = push_swap

CFLAGS = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(CFILE)
	$(CFLAGS) $(CFILE) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all