/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:06:57 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 20:54:34 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_with_precision(char *str, t_spec *spec)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (spec->is_precision)
	{
		while (i < spec->precision && str[i])
		{
			len += putchar_fd(str[i], 1);
			i++;
		}
	}
	else
	{
		len += putstr_fd(str, 1);
	}
	return (len);
}

static size_t	get_print_len(char *str, t_spec *spec)
{
	size_t	i;

	i = 0;
	if (spec->is_precision == false)
		return (ft_strlen(str));
	while (str[i] && i < spec->precision)
		i++;
	return (i);
}

static size_t	handle_null(t_spec *spec)
{
	size_t	null_str_size;
	size_t	pad_len;
	size_t	printed_len;

	pad_len = 0;
	printed_len = 0;
	null_str_size = get_print_len("(null)", spec);
	if (null_str_size != 6)
		null_str_size = 0;
	if (spec->width > null_str_size)
		pad_len = spec->width - null_str_size;
	if (spec->is_minus == false)
		printed_len += print_pad(pad_len);
	if (null_str_size >= 6)
		printed_len += putstr_fd("(null)", 1);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (printed_len);
}

size_t	print_str(char *str, t_spec *spec)
{
	size_t	printed_len;
	size_t	print_len;
	size_t	pad_len;

	if (str == NULL)
		return (handle_null(spec));
	print_len = get_print_len(str, spec);
	printed_len = 0;
	pad_len = 0;
	if (spec->width > print_len)
		pad_len = spec->width - print_len;
	if (spec->is_minus == false)
		printed_len += print_pad(pad_len);
	printed_len += print_with_precision(str, spec);
	if (spec->is_minus)
		printed_len += print_pad(pad_len);
	return (printed_len);
}
