/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:00:52 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/15 18:40:05 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	sort_a(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->data < lstlast(*a)->data)
		sa(*a);
	else if ((*a)->data > lstlast(*a)->data && (*a)->data > (*a)->next->data)
		ra(a);
	else if ((*a)->next->data > lstlast(*a)->data)
		rra(a);
}

int	is_sorted(t_stack **stack, char c)
{
	t_stack	*temp;
	int		des;
	int		asc;

	temp = *stack;
	des = 0;
	asc = 0;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			des++;
		else
			asc++;
		temp = temp->next;
	}
	if ((c == 'a' && !des) || (c == 'b' && !asc))
		return (1);
	return (0);
}

int	min_index(t_stack **stack)
{
	t_stack	*temp;
	int		min;
	int		i;
	int		min_index;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = (*stack)->next;
	min = (*stack)->data;
	i = 1;
	min_index = 0;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}
