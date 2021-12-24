/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:36:08 by abouchfa          #+#    #+#             */
/*   Updated: 2021/12/23 17:36:33 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	lst_swap(a, a->next);
	ft_putstr("sa\n");
}

void 	sb(t_stack *b)
{
	lst_swap(b, b->next);
	ft_putstr("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	lst_swap(b, b->next);
	lst_swap(a, a->next);
	ft_putstr("ss\n");
}

void pa(t_stack **a, t_stack **b)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->data = (*b)->data;
	new->next = NULL;
	lstadd_front(a, new);
	*b = (*b)->next;
	ft_putstr("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack *new = malloc(sizeof(t_stack));
	new->data = (*a)->data;
	new->next = NULL;
	lstadd_front(b, new);
	*a = (*a)->next;
	ft_putstr("pb\n");
}

void	ra(t_stack **a)
{
	t_stack *tmp = *a;
	*a = (*a)->next;
	lstadd_back(a, tmp);
	tmp->next = NULL;
	ft_putstr("ra\n");
}

void	rb(t_stack **b)
{
	t_stack *tmp = *b;
	*b = (*b)->next;
	lstadd_back(b, tmp);
	tmp->next = NULL;
	ft_putstr("rb\n");
}

void 	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack *tmp = lstlast(*a);
	tmp->prev->next = NULL;
	lstadd_front(a, tmp);
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	t_stack *tmp = lstlast(*b);
	tmp->prev->next = NULL;
	lstadd_front(b, tmp);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}