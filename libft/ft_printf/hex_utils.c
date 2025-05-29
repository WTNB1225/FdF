/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:35:35 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 20:59:19 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_lower_hex(unsigned int num)
{
	const char	*hex_table = "0123456789abcdef";
	size_t		len;

	len = 0;
	if (num >= 16)
	{
		len += print_lower_hex(num / 16);
	}
	putchar_fd(hex_table[num % 16], 1);
	len += 1;
	return (len);
}

size_t	print_upper_hex(unsigned int num)
{
	const char	*hex_table = "0123456789ABCDEF";
	size_t		len;

	len = 0;
	if (num >= 16)
	{
		len += print_upper_hex(num / 16);
	}
	putchar_fd(hex_table[num % 16], 1);
	len += 1;
	return (len);
}

size_t	print_lower_hex_address(uintptr_t num)
{
	const char	*hex_table = "0123456789abcdef";
	size_t		len;

	len = 0;
	if (num >= 16)
	{
		len += print_lower_hex_address(num / 16);
	}
	putchar_fd(hex_table[num % 16], 1);
	len += 1;
	return (len);
}

size_t	print_address(uintptr_t ptr)
{
	const char	*hex_table = "0123456789abcdef";
	size_t		len;

	ft_putstr_fd("0x", 1);
	len = 2;
	if (ptr >= 16)
	{
		len += print_lower_hex_address(ptr / 16);
	}
	ft_putchar_fd(hex_table[ptr % 16], 1);
	len += 1;
	return (len);
}
