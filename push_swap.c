/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/01/09 16:19:26 by abdeljalilb      ###   ########.fr       */
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
	if (is_sorted(a, 'a'))
		return;
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

int	get_frame(int size)
{
	if (size >= 500)
		return (70);
	if (size >= 400)
		return (60);
	if (size >= 300)
		return (50);
	if (size >= 200)
		return (40);
	if (size >= 100)
		return (60);
	if (size >= 50)
		return (30);
	else
		return (size);
}

void partition(t_stack **a, t_stack **b, int size, int frame)
{
	int tmp = size;
	if (size < frame)
		frame = size;
	int pivot = get_medium(a, size, frame);
	while (--tmp)
	{
		if ((*a)->data <= pivot)
		{
			pb(b, a);
			size--;
		}
		else 
			ra(a);
	}
	if (size > 2)
		partition(a, b, size, frame);
}
int main(int ac, char **av)
{
	int size;
	if (ac < 2)
		return (0);
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	size = ac - 1;
	if (set_a(av + 1, size, &a))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (is_sorted(&a, 'a'))
		return 0;
	if (size > 10)
	{
		partition(&a, &b, size, get_frame(size));
		pb_loop(&b, &a);
		sortBigStack(&a, &b, size);
	}
	else
	{
		sortSmallStack(&a, &b, size);
		pa_loop(&a, &b);
	}
	return 0;
}