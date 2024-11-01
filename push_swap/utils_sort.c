/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:32:54 by smercado          #+#    #+#             */
/*   Updated: 2024/11/01 12:01:24 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_max_index(t_stack *stack)
{
	long	max_stored;
	t_stack	*tmp;
	t_stack	*max_node;

	tmp = stack;
	if (!stack)
		return (0);
	max_stored = LONG_MIN;
	while (tmp)
	{
		if (tmp->index > max_stored)
		{
			max_stored = tmp->index;
			max_node = tmp;
		}
		tmp = tmp->next;
	}
	return (max_node->index);
}

void	print_all(t_stack **stack)
{
	t_stack *tmp;
	int	size = ft_get_size(*stack);
	tmp = *stack;
	while (tmp)
	{
		ft_printf("stack content: %d, index: %d, pos: %d\n", tmp->content, tmp->index, tmp->pos);
		ft_printf("stack cost_a: %d, cost_b %d, target: %d, size: %d\n", tmp->cost_a, tmp->cost_b, tmp->target, size);
		tmp = tmp->next;
	}
}

int	find_lowest_pos(t_stack **stack)
{
	int	stored;
	t_stack	*tmp;
	t_stack *low_node;

	tmp = *stack;
	if (!stack)
		return (0);
	stored = INT_MAX;
	while (tmp)
	{
		if (tmp->index < stored)
		{
			stored = tmp->index;
			low_node = tmp;
		}
		tmp = tmp->next;
	}
	return (low_node->pos);
}

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = (*stack);
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_index(t_stack *a)
{
	int	size;
	t_stack *tmp;
	t_stack *big;
	int	max_value;

	size = ft_get_size(a) + 1;
	while (--size > 0)
	{
		tmp = a;
		big = NULL;
		max_value = INT_MIN;
		while (tmp)
		{
			if (tmp->content == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (max_value < tmp->content && tmp->index == 0)
			{
				max_value = tmp->content;
				big = tmp;
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		big->index = size;
	}
}
