/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:46:37 by abouchfa          #+#    #+#             */
/*   Updated: 2021/12/24 16:31:12 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_arr(t_stack **stack)
{
	t_stack *temp = *stack;
	while (temp)
	{
		printf("data: %d\n", temp->data);
		temp = temp->next; 
	}
}

void sortStack(t_stack **a, t_stack **b)
{
    if (*a) {
		if ((*a)->next && (*a)->data > lstlast(*a)->data)
			rra(a);
		if ((*a)->next && (*a)->data > (*a)->next->data)
			sa(*a);
		if (is_sorted(a)) 
			pa_loop(a, b);
		else
		{
			pb(b, a);
        	sortStack(a, b);
		}
    } 
	else
		pa_loop(a,b);
	if (!is_sorted(a))
		sortStack(a, b);
}

void operationsTests(t_stack **a, t_stack **b)
{
	sa(*a);
	pb(b, a);
	pb(b, a);
	pb(b, a);
	rr(a, b);
	rrr(a, b);
	sa(*a);
	pa(a, b);
	pa(a, b);
	pa(a, b);
	printf("a ==>\n");
	print_arr(&a);
	printf("b ==>\n");
	print_arr(&b);
}

void sortStack(t_stack **a, t_stack **b)
{
    if (*a) {
		if ((*a)->next && (*a)->data > lstlast(*a)->data)
			rra(a);
		if ((*a)->next && (*a)->data > lstlast(*a)->data && (*a)->data > (*a)->next->data)
			ra(a);
		if ((*a)->next && (*a)->data > (*a)->next->data)
			sa(*a);
		if (is_sorted(a, 'a'))
			pa_loop(a, b);
		else
			pb(b, a);
    } else
		pa_loop(a, b);
	if (!is_sorted(a, 'a'))
		sortStack(a, b);
}