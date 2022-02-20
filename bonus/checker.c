/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:57:37 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/20 06:38:38 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	op_driver(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(*a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(*b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(*a, *b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

char	*get_op(int fd)
{
	int		i;
	int		len;
	char	*temp;
	char	*line;
	char	buffer;

	line = NULL;
	buffer = 0;
	while (buffer != '\n' && read(fd, &buffer, 1) > 0)
	{
		i = -1;
		len = 0;
		temp = line;
		if (line)
			while (line[len])
				len++;
		line = malloc(len + 2);
		while (++i < len)
			line[i] = temp[i];
		line[i++] = buffer;
		line[i] = 0;
		if (line)
			free(temp);
	}
	return (line);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*op;

	while (1)
	{
		op = get_op(0);
		if (!op)
		{
			if (is_sorted(a, 'a'))
				ft_putstr("OK\n", 1);
			else
				ft_putstr("KO\n", 1);
			break ;
		}
		else if (!op_driver(op, a, b))
		{
			ft_putstr("Error\n", 2);
			break ;
		}
		if (op)
			free(op);
	}
	if (op)
		free(op);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (set_a(av + 1, ac - 1, &a))
	{
		ft_putstr("Error\n", 2);
		return (1);
	}
	checker(&a, &b);
	return (0);
}
