/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeljalilbouchfar <abdeljalilbouchfar@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 10:55:23 by abouchfa          #+#    #+#             */
/*   Updated: 2022/01/03 10:47:54 by abdeljalilb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_stack	*lstnew(int n)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = n;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
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