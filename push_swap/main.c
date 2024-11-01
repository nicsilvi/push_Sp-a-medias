/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:32:55 by smercado          #+#    #+#             */
/*   Updated: 2024/10/31 14:53:59 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack **stack_a, t_args *args)
{
	int		i;
	int		num;

	i = 0;
	while (args->lent -1 > i)
	{
		num = ft_atoi(args->spl_args[i]);
		stack_add_bottom(stack_a, stack_new(num));
		i++;
	}
	if (args->is_str == 1)
		ft_freearray(args->spl_args);
	get_index(*stack_a);
}

void	init_args(t_args *args, char **argv, int argc)
{
	if (argc == 2)
	{
		if (ft_strchr(argv[1], ' ') == NULL)
			exit(-1);
		args->is_str = 1;
		args->spl_args = check_errors_str(argv[1]);
		if (args->spl_args == NULL)
			ft_error(NULL, NULL);
		args->lent = ft_count_words(argv[1], ' ') + 1;
	}
	else
	{
		args->spl_args = argv + 1;
		args->is_str = 0;
		args->lent = argc;
	}
}

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(-1);
	if (check_errors_argv(&stack_a, argc, argv) == -1)
		ft_error(NULL, NULL);
	size = ft_get_size(stack_a);
	choose_sort(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
