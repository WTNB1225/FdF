/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:50:38 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:58:47 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	get_digit(int n)
{
	size_t	digit;

	digit = 1;
	if (n < 0)
		digit++;
	while (n / 10)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	size_t			digit;
	long long int	tmp;

	digit = get_digit(n);
	tmp = n;
	if (n < 0)
		tmp *= -1;
	ptr = (char *)malloc(sizeof(char) * (digit + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[digit] = '\0';
	digit--;
	while (tmp / 10)
	{
		ptr[digit] = (tmp % 10) + '0';
		tmp /= 10;
		digit--;
	}
	ptr[digit] = (tmp % 10) + '0';
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
	char *p1 = ft_itoa(-2147483648);
	char *p2 = ft_itoa(2147483647);
	char *p3 = ft_itoa(-42);
	char *p4 = ft_itoa(0);
	printf("%s\n", p1);
	printf("%s\n", p2);
	printf("%s\n", p3);
	printf("%s\n", p4);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
}
*/
