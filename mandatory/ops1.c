/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:36:08 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/17 15:51:48 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (!a)
		return ;
	lst_swap(a, a->next);
	ft_putstr("sa\n", 1);
}

void	sb(t_stack *b)
{
	if (!b)
		return ;
	lst_swap(b, b->next);
	ft_putstr("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new;

	if (!*b)
		return ;
	new = *b;
	*b = (*b)->next;
	new->next = NULL;
	lstadd_front(a, new);
	ft_putstr("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*new;

	if (!*a)
		return ;
	new = *a;
	*a = (*a)->next;
	new->next = NULL;
	lstadd_front(b, new);
	ft_putstr("pb\n", 1);
}
