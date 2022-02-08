/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/08 13:30:11 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (size > 200)
		return size / 4;
	else if (size > 100)
		return size / 3;
	else if (size > 20)
		return size / 2;
	else
	 	return size;
}

void partition(t_stack **a, t_stack **b, int size)
{
	int tmp = size;
	int frame = get_frame(size);
	int i = 0;
	int pivot = get_medium(a, size, frame);
	while (--tmp)
	{
		if ((*a)->data <= pivot)
		{
			pb(b, a);
			size--;
			i++;
			if (frame / 2 == i)
				break ;
		}
		else 
			ra(a);
	}
	if (size > 1)
		partition(a, b, size);
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
		partition(&a, &b, size);
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