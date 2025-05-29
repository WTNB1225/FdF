/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 01:14:11 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:04:12 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	zero_and_precision_zero(t_spec *spec, char *n_str)
{
	size_t	pad_len;
	size_t	printed_len;

	pad_len = spec->width;
	printed_len = 0;
	while (pad_len > 0)
	{
		printed_len += putchar_fd(' ', 1);
		pad_len--;
	}
	free(n_str);
	return (printed_len);
}

size_t	print_pad(size_t pad_len)
{
	size_t	printed_len;

	printed_len = 0;
	while (pad_len > 0)
	{
		printed_len += putchar_fd(' ', 1);
		pad_len--;
	}
	return (printed_len);
}

size_t	print_zero_or_space(t_spec *spec, size_t pad_len)
{
	size_t	printed_len;

	printed_len = 0;
	if (spec->is_zero && spec->is_precision == false)
	{
		while (pad_len > 0)
		{
			printed_len += putchar_fd('0', 1);
			pad_len--;
		}
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
