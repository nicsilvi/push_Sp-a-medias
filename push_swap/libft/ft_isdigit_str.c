/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:02:02 by smercado          #+#    #+#             */
/*   Updated: 2024/10/28 09:24:12 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
 
int	ft_isdigit_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
	{
		len++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			len++;
		i++;
	}
	if (len == ft_strlen(str))
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	c = 48;
	int ret;

	ret = ft_isdigit(c);
	printf("%d\n", ret);

	return (0);
}*/
