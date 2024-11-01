/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sortation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:16:02 by smercado          #+#    #+#             */
/*   Updated: 2024/11/01 12:15:40 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_get_size(*a);
	while (size > 4)
	{
		size = ft_get_size(*a);
		if ((*a)->index > size / 2)
			do_pb(a, b);
		else
			do_ra(a);
	}
}

int	costs_to_up_a(t_stack **stack, int target)
{
	t_stack *tmp;
	int	size;
	int	moves;

	get_position(stack);
	size = ft_get_size(*stack);
	tmp = *stack;
	while (tmp->pos != target)
		tmp = tmp->next;
	if (tmp->pos <= size / 2)
		moves = tmp->pos;
	else
		moves = size - tmp->pos;
	return (moves);
}

void	costs_to_up_b(t_stack **stack, t_stack **a)
{
	t_stack *tmp;
	int	size;
	int	moves;

	size = ft_get_size(*stack);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->pos <= size / 2)
			moves = tmp->pos;
		else
			moves = tmp->pos - size;
		tmp->cost_b = moves;
		tmp->cost_a = costs_to_up_a(a, tmp->target);
		tmp = tmp->next;
	}
}

void	find_cheapest(t_stack **a, t_stack **b)
{
	t_stack		*tmp;
	t_stack		*tmp_a;
	int			cheapest;
	int			cost_a;
	int			cost_b;

	tmp = *b;
	tmp_a = *a;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs(tmp->cost_a) + abs(tmp->cost_b) < cheapest)
		{
			cheapest = abs(tmp->cost_a) + abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	make_order(a, b, cost_a, cost_b);
}
