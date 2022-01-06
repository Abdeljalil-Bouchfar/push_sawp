# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 10:14:22 by abouchfa          #+#    #+#              #
#    Updated: 2022/01/06 09:01:23 by abdeljalilb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = push_swap.c operations.c utils/lst_utils.c get_medium.c \
		utils/io_utils.c utils/opr_utils.c utils/sort_utils.c

EXC = push_swap

CFLAGS = gcc -Wall -Wextra -Werror

all:
	$(CFLAGS) $(CFILE) -o $(EXC)

clean:
	rm -rf $(EXC)

fclean: clean

re: fclean all