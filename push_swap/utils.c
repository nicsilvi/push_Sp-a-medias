/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:32:12 by smercado          #+#    #+#             */
/*   Updated: 2024/10/31 11:48:51 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (!stack->next)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

int	ft_get_size(t_stack *stack)
{
	int	count;
	t_stack	*temp;

	if (!stack)
		return (0);
	temp = stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack *temp;
	
	if (!new)
		return ;
	if (!(*stack))
		*stack = new;
	else
	{
		temp = ft_stack_last(*stack);
		temp->next = new;
	}
}

t_stack	*stack_new(int content)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = 0;
	new->target = -1;
	new->cost_a = -1;
	new->pos = -1;
	new->cost_b = -1;
	return (new);
}

void	free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
