/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:40:00 by smercado          #+#    #+#             */
/*   Updated: 2024/11/01 11:34:37 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	targets(t_stack **a, t_stack **stack_b)
{
	t_stack *b;
	int		target;

	b = *stack_b;
	target = 0;
	while (b)
	{
		target = find_objective_b(a, b);
		b->target = target;
		b = b->next;
	}
}

//encuentro el siguiente num (el siguiente grande)
int	find_objective_b(t_stack **a, t_stack *b)
{
	int	object;
	int	target;
	t_stack *tmp;

	tmp = *a;
	target = 0;
	object = INT_MAX;
	while (tmp)
	{
		if (tmp->index > b->index && tmp->index < object)
		{
			object = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (object == INT_MAX)
		target = find_lowest_pos(a);
	return (target);
}

int	find_median(t_stack *a)
{
	int	size;
	int	median;

	size = ft_get_size(a);
	median = size / 2;
	return (median);
}
