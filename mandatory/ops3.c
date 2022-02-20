/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:19:12 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/17 10:36:52 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = lstlast(*a);
	if (tmp->prev)
		tmp->prev->next = NULL;
	lstadd_front(a, tmp);
	ft_putstr("rra\n", 1);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = lstlast(*b);
	if (tmp->prev)
		tmp->prev->next = NULL;
	lstadd_front(b, tmp);
	ft_putstr("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
