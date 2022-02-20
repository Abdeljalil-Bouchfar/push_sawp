/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:04 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/20 06:35:54 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max_three(t_stack **a, t_stack **b, int b_size,
						t_nbr_info	*max_three)
{
	int			i;

	i = -1;
	while (++i < 3)
	{
		if (max_three[i].index > b_size / 2)
			while ((*b)->data != max_three[i].nbr)
				rrb(b);
		else
			while ((*b)->data != max_three[i].nbr)
				rb(b);
		pa(a, b);
		if (i < 2 && is_min(max_three, max_three[i].nbr))
			ra(a);
		if (*a && (*a)->next && (*a)->data > (*a)->next->data)
			sa(*a);
	}
	if (*a && (*a)->data > lstlast(*a)->data)
		rra(a);
}

void	sort_big_stack(t_stack **a, t_stack **b, int size)
{
	t_nbr_info	*max_three;

	partition(a, b, size);
	max_three = malloc (3 * sizeof(t_nbr_info));
	while (size > 2)
	{
		get_max_three(b, max_three, size);
		push_max_three(a, b, size, max_three);
		size -= 3;
	}
	while (*b)
	{
		pa(a, b);
		if (*a && (*a)->next && (*a)->data > (*a)->next->data)
			sa(*a);
	}
	free(max_three);
}

void	sort_small_stack(t_stack **a, t_stack **b, int size)
{
	int	i;

	while (size > 3)
	{
		i = min_index(a);
		if (i > size / 2)
			while (i++ < size)
				rra(a);
		else
			while (i--)
				ra(a);
		pb(b, a);
		size--;
	}
	while (!is_sorted(a, 'a'))
		sort_a(a);
	while (*b)
		pa(a, b);
}

int	main(int ac, char **av)
{
	int		size;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	size = ac - 1;
	if (set_a(av + 1, size, &a))
	{
		ft_putstr("Error\n", 2);
		return (1);
	}
	if (is_sorted(&a, 'a'))
		return (0);
	if (size <= 10)
		sort_small_stack(&a, &b, size);
	else
		sort_big_stack(&a, &b, size);
	ft_lstclear(&a);
	return (0);
}
