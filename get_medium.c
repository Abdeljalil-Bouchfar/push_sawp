#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void get_arr(t_stack **a, int *tab)
{
	t_stack *tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

int	get_medium(t_stack **a, int size, int frame)
{
	int	i;
	int	j;
	int tab[size];
	int	min_index;

	i = 0;
	get_arr(a, tab);
	while (i < size - 1)
	{
		j = i + 1;
		min_index = i;
		while (j < size)
		{
			if (tab[min_index] > tab[j])
				min_index = j;
			j++;
		}
		ft_swap(&tab[min_index], &tab[i]);
		i++;
	}
	i = frame / 2;
	return tab[i];
}