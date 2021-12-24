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
	int 		i;
	long int 	tmp;
	t_stack		*temp_stack;

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

void	pa_loop(t_stack **a, t_stack **b)
{
	t_stack *temp = *b;
	while (temp)
	{
		pa(a, b);
		temp = temp->next;
	}
}

void	pb_loop(t_stack **b, t_stack **a)
{
	t_stack *temp = *a;
	while (temp)
	{
		pb(b, a);
		temp = temp->next;
	}
}

int	is_sorted(t_stack **stack, char c)
{
	t_stack *temp = *stack;
	int des;
	int	asc;

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

int	is_MaxInTop(t_stack **stack)
{
	t_stack *temp = *stack;

	if (!temp || !temp->next)
		return (1);
	int top = temp->data;
	temp = temp->next;
	while (temp)
	{
		if (temp->data > top)
			return(0);
		temp = temp->next;
	}
	return (1);
}



void sort_b(t_stack **b)
{
		if ((*b)->next && (*b)->data < lstlast(*b)->data && (*b)->data < (*b)->next->data)
			rb(b);
		if ((*b)->next && (*b)->data < lstlast(*b)->data)
			rrb(b);
		if ((*b)->next && (*b)->data < (*b)->next->data)
			sb(*b);
}

void sortStack(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	while (!is_MaxInTop(b))
		rb(b);
	pa(a, b);
	sortStack(a, b);
}

void partition(t_stack **a, t_stack **b, int len)
{
	int pivot = (*a)->data;
	pb(b, a);
	while (--len)
	{
		if ((*a)->data < pivot)
		{
			pb(b, a);
			sort_b(b);
		}
		else
			ra(a);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (set_a(av + 1, ac - 1, &a))
	{
		ft_putstr("Error\n");
		return (1);
	}
	partition(&a, &b, ac - 1);
	pb_loop(&b, &a);
	// printf("a =======\n");
	// print_arr(&a);
	// printf("b =======\n");
	// print_arr(&b);
	sortStack(&a, &b);
	printf("sorted ======= %d\n", is_sorted(&a, 'a'));
	// print_arr(&a);
	return 0;
}