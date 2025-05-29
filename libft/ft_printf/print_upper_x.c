/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upper_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:09:19 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:02:11 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_hash_num_preci_upper_x(unsigned int n,
	char *hex_char, t_spec *spec)
{
	size_t	printed_len;
	size_t	i;
	size_t	num_of_zero;
	size_t	hex_len;

	printed_len = 0;
	i = 0;
	num_of_zero = 0;
	hex_len = ft_strlen(hex_char);
	if (spec->is_precision)
	{
		if (spec->precision > hex_len)
			num_of_zero = spec->precision - hex_len;
		while (i++ < num_of_zero)
			printed_len += putchar_fd('0', 1);
	}
	if (spec->is_hash && n != 0)
		printed_len += putstr_fd("0X", 1);
	printed_len += print_upper_hex(n);
	return (printed_len);
}

int	print_upper_x(unsigned int n, t_spec *spec)
{
	char	*hex_char;
	size_t	print_len;
	size_t	pad_len;
	size_t	printed_len;

	hex_char = get_upper_hex(n);
	print_len = ft_strlen(hex_char);
	pad_len = 0;
	printed_len = 0;
	if (hex_char == NULL)
		return (-1);
	if (spec->is_precision && spec->precision > print_len)
		print_len = spec->precision;
	if (spec->is_hash && n != 0)
		print_len += 2;
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	if (spec->is_precision && spec->precision == 0 && n == 0)
		return (zero_and_precision_zero(spec, hex_char));
	if (spec->is_minus == false)
		printed_len += print_zero_or_space(spec, pad_len);
	printed_len += print_hash_num_preci_upper_x(n, hex_char, spec);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (free(hex_char), printed_len);
}
