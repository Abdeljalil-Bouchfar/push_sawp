# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 10:14:22 by abouchfa          #+#    #+#              #
#    Updated: 2021/12/22 10:59:55 by abouchfa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = push_swap.c utils.c operations.c lst_utils.c

EXC = push_swap

CFLAGS = gcc -Wall -Wextra -Werror

all:
	$(CFLAGS) $(CFILE) -o $(EXC)

clean:
	rm -rf $(EXC)

fclean: clean

re: fclean all