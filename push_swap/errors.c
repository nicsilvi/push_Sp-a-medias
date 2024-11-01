/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:17:12 by smercado          #+#    #+#             */
/*   Updated: 2024/10/31 13:57:14 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	check_errors_argv(t_stack **stack_a, int argc, char **argv)
{
	long	lnb;
	int		i;
	t_args	args;

	i = 0;
	args.spl_args = NULL;
	init_args(&args, argv, argc);
	while (i < args.lent - 1)
	{
		if (ft_isdigit_str(args.spl_args[i]))
			lnb = ft_atoi(args.spl_args[i]);
		if (!check_error_int(lnb) || (!check_repeated(lnb, args.spl_args, i)))
		{
			if (args.is_str)
				return (ft_freearray(args.spl_args), -1);
			else
				return (-1);
		}
		i++;
	}
	init_stacks(stack_a, &args);
	return (0);
}

char	**check_errors_str(char *str)
{
	int		i;
	char	**array;
	
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 32 \
		|| str[i] == '-' || str[i] == '+')
			i++;
		else
			break ;
	}
	if (str[i] == '\0')
	{
		array = ft_split(str, ' ');
		return (array);
	}
	else
		return (NULL);
}

int	check_error_int(long nb)
{
	if ((nb > INT_MAX) || (nb < INT_MIN))
		return (0);
	return (1);
}

int check_repeated(long nb, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == nb)
			return (0);
		i++;
	}
	return (1);
}
