/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:11:11 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:00:07 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_sign(int n, t_spec *spec)
{
	if (n < 0)
		return (putchar_fd('-', 1));
	if (spec->is_space)
		return (putchar_fd(' ', 1));
	else if (spec->is_plus)
		return (putchar_fd('+', 1));
	else
		return (0);
}

static size_t	print_num_and_precision(int n, t_spec *spec,
	size_t n_abs_len, char *str)
{
	size_t	printed_len;
	size_t	num_of_zero;
	size_t	i;

	i = 0;
	printed_len = 0;
	num_of_zero = 0;
	if (!(spec->is_minus == false && spec->is_zero
			&& spec->is_precision == false))
		printed_len += print_sign(n, spec);
	if (spec->is_precision)
	{
		if (spec->precision > n_abs_len)
			num_of_zero = spec->precision - n_abs_len;
		while (i < num_of_zero)
		{
			printed_len += putchar_fd('0', 1);
			i++;
		}
	}
	if (!(spec->is_minus == false && spec->is_zero
			&& spec->is_precision == false))
		printed_len += putstr_fd(str, 1);
	return (printed_len);
}

size_t	print_int(int n, t_spec *spec)
{
	char	*n_str;
	size_t	abs_n;
	size_t	print_len;
	size_t	pad_len;
	size_t	printed_len;

	abs_n = get_abs(n);
	n_str = ft_stoa(abs_n);
	print_len = ft_strlen(n_str);
	pad_len = 0;
	printed_len = 0;
	if (n_str == NULL)
		return (-1);
	print_len = int_get_print_len(spec, print_len, n);
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	if (n == 0 && spec->is_precision && spec->precision == 0)
		return (zero_and_precision_zero(spec, n_str));
	if (spec->is_minus == false)
		printed_len += int_print_space_or_zero(spec, n, pad_len, n_str);
	printed_len += print_num_and_precision(n, spec, ft_strlen(n_str), n_str);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (free(n_str), printed_len);
}
