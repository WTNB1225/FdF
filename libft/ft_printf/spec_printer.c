/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:07:29 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:08:49 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spec(t_spec *spec, va_list ap)
{
	if (spec->specifier == 'c')
		return (print_char((char)va_arg(ap, int), spec));
	else if (spec->specifier == 's')
		return (print_str(va_arg(ap, char *), spec));
	else if (spec->specifier == 'p')
		return (print_p(va_arg(ap, void *), spec));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (print_int(va_arg(ap, int), spec));
	else if (spec->specifier == 'u')
		return (print_u(va_arg(ap, unsigned int), spec));
	else if (spec->specifier == 'x')
		return (print_x(va_arg(ap, unsigned int), spec));
	else if (spec->specifier == 'X')
		return (print_upper_x(va_arg(ap, unsigned int), spec));
	else if (spec->specifier == '%')
		return (putchar_fd('%', 1));
	return (0);
}
