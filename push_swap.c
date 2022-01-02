/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:29:04 by abouchfa          #+#    #+#             */
/*   Updated: 2021/12/24 16:37:58 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_arr(t_stack **stack)
{
	t_stack *temp = *stack;
	while (temp)
	{
		printf("data: %d\n", temp->data);
		temp = temp->next;
	}
}

int set_a(char **av, int len, t_stack **a)
{
	int i;
	long int tmp;
	t_stack *temp_stack;

	if (check_input_error(av, len))
		return (1);
	i = 0;
	while (i < len)
	{
		temp_stack = malloc(sizeof(t_stack));
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (1);
		temp_stack->data = tmp;
		temp_stack->next = NULL;
		temp_stack->prev = NULL;
		lstadd_back(a, temp_stack);
		i++;
	}
	return (0);
}

void pa_loop(t_stack **a, t_stack **b)
{
	t_stack *temp = *b;
	while (temp)
	{
		pa(a, b);
		temp = temp->next;
	}
}

void pb_loop(t_stack **b, t_stack **a)
{
	t_stack *temp = *a;
	while (temp)
	{
		pb(b, a);
		temp = temp->next;
	}
}

int is_sorted(t_stack **stack, char c)
{
	t_stack *temp = *stack;
	int des;
	int asc;

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

int minIndex(t_stack **stack)
{
	t_stack *temp = *stack;

	if (!temp || !temp->next)
		return (0);
	int min = temp->data;
	int i = 1;
	int min_index = 0;
	temp = temp->next;
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

void sort_a(t_stack **a)
{
	if ((*a)->next && (*a)->data > lstlast(*a)->data && (*a)->data > (*a)->next->data)
		ra(a);
	else if ((*a)->next && (*a)->data > lstlast(*a)->data)
		rra(a);
	if ((*a)->next && (*a)->data > (*a)->next->data)
		sa(*a);
}

void sortStack(t_stack **a, t_stack **b, int len)
{
	sort_a(a);
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
		sortStack(a, b, --len);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (set_a(av + 1, ac - 1, &a))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (is_sorted(&a, 'a'))
		return 0;
	// partition(&a, &b, ac - 1);
	// pb_loop(&b, &a);
	// printf("a =======\n");
	// print_arr(&a);
	// printf("b =======\n");
	// print_arr(&b);
	sortStack(&a, &b, ac - 1);
	pa_loop(&a, &b);
	//printf("sorted =======> %d\n", is_sorted(&a, 'a'));
	// printf("a =======\n");
	// print_arr(&a);
	return 0;
}