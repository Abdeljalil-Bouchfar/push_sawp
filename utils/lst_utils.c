/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:55:23 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/15 15:02:19 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	lst_swap(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->data;
	a->data = b->data;
	b->data = tmp;
}

t_stack	*lstlast(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (stack);
	temp = stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	new->prev = temp;
	temp->next = new;
}

void	lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
		return ;
	if (*lst)
	{
		new->next = *lst;
		(*lst)->prev = new;
	}
	*lst = new;
	new->prev = NULL;
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
}
