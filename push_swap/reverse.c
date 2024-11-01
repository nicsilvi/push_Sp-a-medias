/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:36:36 by smercado          #+#    #+#             */
/*   Updated: 2024/11/01 11:25:44 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack *ulti;
	t_stack *penulti;

	penulti = *stack;
	while (penulti->next->next)
		penulti = penulti->next;
	ulti = penulti->next;
	penulti->next = NULL;
	ulti->next = *stack;
	*stack = ulti;
}

void	do_rra(t_stack **stack_a)
{
	reverse(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack **stack_b)
{
	reverse(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
	ft_printf("rrr\n");
}
