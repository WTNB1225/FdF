/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:55:57 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/28 16:40:38 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\r'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}

static size_t	str_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	long long int	sum;
	int				sign;

	i = 0;
	sign = 1;
	sum = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str_is_num(str[i]))
			sum = sum * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return ((int)(sum * sign));
}

/*
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	assert(ft_atoi("2147483647") == atoi("2147483647"));
	assert(ft_atoi("-2147483648") == atoi("-2147483648"));
	assert(ft_atoi("   -2147483648") == atoi("   -2147483648"));
	assert(ft_atoi("  -2147483648") == atoi("   -2147483648"));
}
*/
