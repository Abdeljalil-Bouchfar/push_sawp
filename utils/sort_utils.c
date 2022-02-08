#include "../push_swap.h"

void sort_a(t_stack **a)
{
	if (!*a || !(*a)->next)
		return;
	if ((*a)->data > lstlast(*a)->data && (*a)->data > (*a)->next->data)
		ra(a);
	if ((*a)->data > lstlast(*a)->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(*a);
}

void sort_b(t_stack **b)
{
	if (!*b || !(*b)->next)
		return ;
	if ((*b)->data < lstlast(*b)->data && (*b)->data < (*b)->next->data)
		rb(b);
	if ((*b)->data < lstlast(*b)->data)
		rrb(b);
	if ((*b)->data < (*b)->next->data)
		sb(*b);
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

int maxIndex(t_stack **stack)
{
	t_stack *temp = *stack;

	if (!temp || !temp->next)
		return (0);
	int max = temp->data;
	int i = 1;
	int max_index = 0;
	temp = temp->next;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (max_index);
}