/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/01/03 11:13:35 by abdeljalilb      ###   ########.fr       */
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

void sortBigStack(t_stack **a, t_stack **b, int len)
{
	int i = maxIndex(b);
	if (i > len / 2)
		while (i++ < len)
			rrb(b);
	else
		while (i--)
			rb(b);
	if (*b)
	{
		pa(a, b);
		sortBigStack(a, b, --len);
	}
}

void sortSmallStack(t_stack **a, t_stack **b, int len)
{
	sort_a(a);
	int i = minIndex(a);
	if (i > len / 2)
		while (i++ < len)
			rra(a);
	else
		while (i--)
			ra(a);
	if (!is_sorted(a, 'a'))
	{
		pb(b, a);
		sortSmallStack(a, b, --len);
	}
}

void partition(t_stack **a, t_stack **b, int len)
{
	int pivot = (*a)->data;
	pb(b, a);
	while (--len)
	{
		if ((*a)->data < pivot)
		{
			pb(b, a);
		}
		else
			ra(a);
	}
}
int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (set_a(av + 1, ac - 1, &a))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (is_sorted(&a, 'a'))
		return 0;
	if (ac > 11)
	{
		partition(&a, &b, ac - 1);
		pb_loop(&b, &a);
		sortBigStack(&a, &b, ac - 1);
	}
	else
	{
		sortSmallStack(&a, &b, ac - 1);
		pa_loop(&a, &b);
	}
	// printf("a =======\n");
	// print_arr(&a);
	// printf("b =======\n");
	// print_arr(&b);
	//pa_loop(&a, &b);
	//printf("sorted =======> %d\n", is_sorted(&a, 'a'));
	// printf("a =======\n");
	// print_arr(&a);
	return 0;
}