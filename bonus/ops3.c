/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:19:12 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/10 11:39:24 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = lstlast(*a);
	tmp->prev->next = NULL;
	lstadd_front(a, tmp);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = lstlast(*b);
	tmp->prev->next = NULL;
	lstadd_front(b, tmp);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
