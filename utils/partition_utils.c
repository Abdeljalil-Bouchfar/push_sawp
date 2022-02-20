/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:39:56 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/19 21:29:24 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	get_frame(int size)
{
	if (size > 200)
		return (size / 8);
	else if (size > 50)
		return (size / 5);
	else if (size > 10)
		return (size / 3);
	else
		return (1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	set_tab(t_stack **a, int *tab, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		min_index;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		min_index = i;
		while (++j < size)
			if (tab[min_index] > tab[j])
				min_index = j;
		ft_swap(&tab[min_index], &tab[i]);
	}
}

int	get_frame_point(t_stack **a, int size, int frame, int med)
{
	int	res;
	int	*tab;

	tab = malloc (sizeof(int) * size);
	if (!tab)
		return ((*a)->data);
	set_tab(a, tab, size);
	if (med)
		res = tab[frame / 2];
	else
		res = tab[frame];
	free(tab);
	return (res);
}

void	partition(t_stack **a, t_stack **b, int a_size)
{
	int	frame_med;
	int	frame_max;
	int	frame;

	while (a_size)
	{
		frame = get_frame(a_size);
		frame_med = get_frame_point(a, a_size, frame, 1);
		frame_max = get_frame_point(a, a_size, frame, 0);
		while (frame--)
		{
			if ((*a)->data <= frame_med
				|| ((*a)->data > frame_med && (*a)->data <= frame_max))
			{
				pb(b, a);
				if ((*b)->data > frame_med && (*b)->data <= frame_max)
					rb(b);
				a_size--;
			}
			else
				ra(a);
		}
	}
}
