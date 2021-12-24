/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:05:27 by abouchfa          #+#    #+#             */
/*   Updated: 2021/12/23 10:18:51 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef	struct	s_stack 
{
    int	data;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

void	ft_putstr(char *str);
long	ft_atol(const char *str);
int		check_input_error (char **av, int len);

void	lst_swap(t_stack *a, t_stack *b);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
t_stack	*lstlast(t_stack *stack);
t_stack	*lstnew(int n);

void	sa(t_stack *a);
void	sb(t_stack *b);
void 	ss(t_stack *a, t_stack *b);
void 	pa(t_stack **a, t_stack **b);
void 	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void 	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif