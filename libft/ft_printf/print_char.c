/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:06:46 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:02:59 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_char(char c, t_spec *spec)
{
	size_t	loop_len;
	size_t	rtn_value;

	loop_len = 0;
	if (spec->width != 0)
		loop_len = spec->width - 1;
	rtn_value = 0;
	if (spec->is_minus)
	{
		rtn_value += putchar_fd(c, 1);
		rtn_value += print_pad(loop_len);
		return (rtn_value);
	}
	else
	{
		rtn_value += print_pad(loop_len);
		rtn_value += putchar_fd(c, 1);
		return (rtn_value);
	}
}
