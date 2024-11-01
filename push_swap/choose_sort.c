/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:46:23 by smercado          #+#    #+#             */
/*   Updated: 2024/11/01 13:00:10 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ordered(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	choose_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && !is_ordered(a))
		do_sa(a);
	if (size == 3 && !is_ordered(a))
		sort_three(a);
	if (size > 3 && !is_ordered(a))
		sort(a, b);
}

void	sort_three(t_stack **stack)
{
	int	max_index;

	if (is_ordered(stack))
		return ;
	max_index = find_max_index(*stack);
	if ((*stack)->index == max_index)
		do_ra(stack);
	else if ((*stack)->next->index == max_index)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}

void	sort(t_stack **a, t_stack **b)
{
	move_a_to_b(a, b);
	printf("stack A despues de movrse\n");
	print_all(a);
	printf("stack B despues de movrse\n");
	print_all(b);
	sort_three(a);

	printf("stack A despues de sort3\n");
	print_all(a);
	while (*b)
	{
		get_position(a);
		get_position(b);
		targets(a, b);
		costs_to_up_b(b, a);
		find_cheapest(a, b);
		printf("dentroo del while a \n");
		print_all(a);
		printf("dentro del while B\n");
		print_all(b);
	}
	printf("stack A despues de while B\n");
	print_all(a);
	printf("stack B \n");
	print_all(b);
	if (!is_ordered(a))
		adjust_a(a);
}

void adjust_a(t_stack **a)
{
	int size;
	int init;

	size = ft_get_size(*a);
	get_position(a);
	init = find_lowest_pos(a);
	if ((*a)->pos < size / 2)
	{
		while (init > 0)
		{
			do_ra(a);
			init--;
		}
	}
	else
	{
		while (init < 0)
		{
			do_rra(a);
			init++;
		}
	}
}
