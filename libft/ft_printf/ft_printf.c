/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:28:11 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 20:59:00 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		p_len;
	int		p_res;
	t_spec	*spec;

	i = 0;
	p_len = 0;
	spec = init_spec();
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%' )
			p_len += putchar_fd(format[i++], 1);
		else
		{
			i = parse_spec(format, i, spec);
			p_res = print_spec(spec, ap);
			if (p_res == -1 || (p_res != -1 && p_res > INT_MAX - p_len))
				return (va_end(ap), free(spec), -1);
			p_len += p_res;
			reset_spec(spec);
		}
	}
	return (va_end(ap), free(spec), p_len);
}
