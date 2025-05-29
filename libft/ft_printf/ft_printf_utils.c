/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:17:07 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/13 01:33:54 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_abs(int n)
{
	long long int	ln;

	ln = n;
	if (n < 0)
		return ((size_t)(-ln));
	return ((size_t)n);
}

size_t	get_digit(int n)
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

size_t	get_s_digit(size_t n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_stoa(size_t n)
{
	char			*ptr;
	size_t			digit;

	digit = get_s_digit(n);
	ptr = (char *)malloc(sizeof(char) * (digit + 1));
	if (ptr == NULL)
		return (NULL);
	ptr[digit--] = '\0';
	if (n == 0)
		ptr[digit--] = '0';
	while (n > 0)
	{
		ptr[digit--] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
