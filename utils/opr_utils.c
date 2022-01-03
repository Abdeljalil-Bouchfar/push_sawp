#include "../push_swap.h"


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