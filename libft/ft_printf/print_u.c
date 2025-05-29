/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:49:56 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:00:47 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_num_and_precision_u(t_spec *spec, char *n_str)
{
	size_t	i;
	size_t	printed_len;
	size_t	num_of_zero;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(n_str);
	printed_len = 0;
	num_of_zero = 0;
	if (spec->is_precision)
	{
		if (spec->precision > n_len)
			num_of_zero = spec->precision - n_len;
		while (i < num_of_zero)
		{
			printed_len += putchar_fd('0', 1);
			i++;
		}
	}
	printed_len += putstr_fd(n_str, 1);
	return (printed_len);
}

int	print_u(unsigned int n, t_spec *spec)
{
	char	*n_str;
	size_t	n_len;
	size_t	pad_len;
	size_t	print_len;
	size_t	printed_len;

	pad_len = 0;
	n_str = ft_stoa(n);
	if (n_str == NULL)
		return (-1);
	n_len = ft_strlen(n_str);
	print_len = n_len;
	printed_len = 0;
	if (spec->is_precision && spec->precision > n_len)
		print_len = spec->precision;
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	if (spec->is_precision && spec->precision == 0 && n == 0)
		return (zero_and_precision_zero(spec, n_str));
	if (spec->is_minus == false)
		printed_len += print_zero_or_space(spec, pad_len);
	printed_len += print_num_and_precision_u(spec, n_str);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (free(n_str), printed_len);
}
