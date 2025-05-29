/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:23:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:01:42 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	int_get_print_len(t_spec *spec, size_t print_len, int n)
{
	size_t	new_print_len;

	new_print_len = print_len;
	if (spec->is_precision && spec->precision > print_len)
		new_print_len = spec->precision;
	if (spec->is_plus || spec->is_space || n < 0)
		new_print_len += 1;
	return (new_print_len);
}

size_t	int_print_space_or_zero(t_spec *spec, int n, size_t pad_len, char *str)
{
	size_t	printed_len;

	printed_len = 0;
	if (spec->is_zero && spec->is_precision == false)
	{
		if (n < 0)
			printed_len += putchar_fd('-', 1);
		while (pad_len > 0)
		{
			printed_len += putchar_fd('0', 1);
			pad_len--;
		}
		printed_len += putstr_fd(str, 1);
	}
	else
	{
		while (pad_len > 0)
		{
			printed_len += putchar_fd(' ', 1);
			pad_len--;
		}
	}
	return (printed_len);
}
