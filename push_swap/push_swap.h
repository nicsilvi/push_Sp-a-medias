/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:38:21 by smercado          #+#    #+#             */
/*   Updated: 2024/10/31 16:08:12 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_args
{
	int		argc;
	char	**spl_args;
	int		is_str;
	int		lent;
}			t_args;

typedef struct	s_stack
{
	
	int		content;
	int		index;
	int		target;
	int		cost_a;
	int		cost_b;
	int		pos;
	struct s_stack *next;
}				t_stack;

//main:
void	init_stacks(t_stack **stack_a, t_args *args);
void	init_args(t_args *args, char **argv, int argc);

//errors:
void	ft_error(t_stack **stack_a, t_stack **stack_b);
int		check_errors_argv(t_stack **stack_a, int argc, char **argv);
char	**check_errors_str(char *str);
int		check_error_int(long nb);
int		check_repeated(long nb, char **argv, int i);

//choose_sort:
int		is_ordered(t_stack **stack);
void	choose_sort(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **stack);
void	sort(t_stack **a, t_stack **b);
void	adjust_a(t_stack **a);

//calculs and start_sortation:
void	targets(t_stack **a, t_stack **stack_b);
int		find_objective_b(t_stack **a, t_stack *b);
void	init_sortation(t_stack **a, t_stack **b);
void	move_a_to_b(t_stack **a, t_stack **b);
int		costs_to_up_a(t_stack **stack, int target);
void	costs_to_up_b(t_stack **stack, t_stack **a);
void	find_cheapest(t_stack **a, t_stack **b);
void	make_order(t_stack **a, t_stack **b, int cost_a, int cost_b);

//operations:
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

//utils:
t_stack	*ft_stack_last(t_stack *stack);
int		ft_get_size(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);
t_stack	*stack_new(int content);
void	free_stack(t_stack **stack);
int		find_max_index(t_stack *stack);
int		find_lowest_pos(t_stack **stack);
void	get_position(t_stack **stack);
void	get_index(t_stack *a);
void	print_all(t_stack **stack);
int		find_median(t_stack *a);

#endif
