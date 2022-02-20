/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:38:16 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/19 20:36:21 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	is_min(t_nbr_info	*max_three, int nbr)
{
	int	j;

	j = -1;
	while (++j < 3)
	{
		if (max_three[j].nbr < nbr)
			return (0);
	}
	return (1);
}

void	ft_sort_tab(t_nbr_info *tab, int size)
{
	int			i;
	int			j;
	int			min_index;
	t_nbr_info	temp;

	i = -1;
	while (++i < size)
	{
		j = i + 1;
		min_index = i;
		while (j < size)
		{
			if (tab[min_index].edge_distance > tab[j].edge_distance)
				min_index = j;
			j++;
		}
		temp = tab[min_index];
		tab[min_index] = tab[i];
		tab[i] = temp;
	}
}

int	ist_in(t_nbr_info *max_three, int index, int counter)
{
	int	i;

	i = -1;
	while (++i < counter)
		if (max_three[i].index == index)
			return (1);
	return (0);
}

void	fill_data(t_nbr_info *max_three, int nbr, int index, int size)
{
	int	destence;

	if (index > size / 2)
		destence = size - index;
	else
		destence = index;
	max_three->nbr = nbr;
	max_three->index = index;
	max_three->edge_distance = destence;
}

void	get_max_three(t_stack **stack, t_nbr_info *max_three, int size)
{
	t_stack	*temp;
	int		is_first;
	int		index;
	int		counter;

	counter = -1;
	while (++counter < 3)
	{
		temp = *stack;
		index = 0;
		is_first = 1;
		while (temp)
		{
			if (!ist_in(max_three, index, counter)
				&& (is_first || temp->data > max_three[counter].nbr))
			{
				fill_data(&max_three[counter], temp->data, index, size);
				is_first = 0;
			}
			temp = temp->next;
			index++;
		}
	}
	ft_sort_tab(max_three, 3);
}
