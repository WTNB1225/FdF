/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:24:20 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:03:45 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	p_get_print_len(t_spec *spec, size_t hex_len)
{
	size_t	print_len;

	print_len = hex_len;
	if (spec->is_precision && (spec->precision > hex_len))
		print_len = spec->precision;
	return (print_len);
}

size_t	p_get_pad_len(t_spec *spec, size_t print_len)
{
	size_t	pad_len;

	pad_len = 0;
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	return (pad_len);
}

static size_t	handle_nil(t_spec *spec)
{
	size_t	null_size;
	size_t	printed_len;
	size_t	print_len;
	size_t	pad_len;

	null_size = 5;
	printed_len = 0;
	pad_len = 0;
	print_len = null_size;
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	if (spec->is_minus == false)
		printed_len += print_pad(pad_len);
	printed_len += putstr_fd("(nil)", 1);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (printed_len);
}

int	print_p(void *ptr, t_spec *spec)
{
	size_t	printed_len;
	size_t	print_len;
	size_t	pad_len;
	size_t	hex_len;
	char	*hex_char;

	if (ptr == NULL)
		return (handle_nil(spec));
	hex_char = get_hex_ptr((uintptr_t)ptr);
	if (hex_char == NULL)
		return (-1);
	hex_len = ft_strlen(hex_char) + 2;
	printed_len = 0;
	print_len = p_get_print_len(spec, hex_len);
	pad_len = p_get_pad_len(spec, print_len);
	if (spec->is_minus)
		printed_len += print_address((uintptr_t)ptr);
	else
		printed_len += print_pad(pad_len);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	else
		printed_len += print_address((uintptr_t)ptr);
	return (free(hex_char), printed_len);
}
