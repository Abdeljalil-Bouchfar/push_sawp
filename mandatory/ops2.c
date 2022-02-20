/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:16:20 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/17 10:36:48 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	lstadd_back(a, tmp);
	ft_putstr("ra\n", 1);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	lstadd_back(b, tmp);
	ft_putstr("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
