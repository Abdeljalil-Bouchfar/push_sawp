/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:39:52 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/19 21:02:28 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	ft_putstr(char *str, int fd)
{
	if (str)
		while (*str)
			write(fd, str++, 1);
}

long	ft_atol(const char *str)
{
	long	n;
	int		minus;

	minus = 1;
	n = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	return (n * minus);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

int	check_input_error(char **av, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (!ft_strcmp(av[i], av[j]))
				return (1);
			j++;
		}
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	set_a(char **av, int len, t_stack **a)
{
	int			i;
	long int	tmp;
	t_stack		*temp_stack;

	if (check_input_error(av, len))
		return (1);
	i = 0;
	while (i < len)
	{
		temp_stack = malloc(sizeof(t_stack));
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || (tmp == 0 && !av[i][0]))
			return (1);
		temp_stack->data = tmp;
		temp_stack->next = NULL;
		temp_stack->prev = NULL;
		lstadd_back(a, temp_stack);
		i++;
	}
	return (0);
}
