/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouchfa <abouchfa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 09:05:27 by abouchfa          #+#    #+#             */
/*   Updated: 2022/02/19 21:01:46 by abouchfa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_nbr_info
{
	int	nbr;
	int	edge_distance;
	int	index;
}	t_nbr_info;

/*			utils/small_sort_utils.c		*/
void	sort_a(t_stack **a);
int		is_sorted(t_stack **stack, char c);
int		min_index(t_stack **stack);

/*			utils/big_sort_utils.c			*/
int		is_min(t_nbr_info	*max_three, int nbr);
void	get_max_three(t_stack **stack, t_nbr_info *max_three, int size);


/*			utils/io_utils.c				*/
void	ft_putstr(char *str, int fd);
long	ft_atol(const char *str);
int		set_a(char **av, int len, t_stack **a);
int		ft_strcmp(char *s1, char *s2);

/*			utils/partition_utils.c			*/
void	partition(t_stack **a, t_stack **b, int a_size);

/*			utils/lst_utils.c				*/
void	lst_swap(t_stack *a, t_stack *b);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstadd_front(t_stack **lst, t_stack *new);
t_stack	*lstlast(t_stack *stack);
void	ft_lstclear(t_stack **lst);

/*			mandatory/ops1.c				*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

/*			mandatory/ops2.c				*/
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/*			mandatory/ops3.c				*/
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif