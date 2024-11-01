/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:42:27 by smercado          #+#    #+#             */
/*   Updated: 2024/10/31 11:56:03 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	rotate_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	reverse_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	up_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			do_ra(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			do_rra(a);
			(*cost_a)++;
		}
	}
}

static void up_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			do_rb(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			do_rrb(b);
			(*cost_b)++;
		}
	}
}

void	make_order(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rotate_ab(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		reverse_ab(a, b, &cost_a, &cost_b);
	up_a(a, &cost_a);
	up_b(b, &cost_b);
	do_pa(a, b);
}
