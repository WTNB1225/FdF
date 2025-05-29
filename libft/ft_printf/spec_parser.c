/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:07:16 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/13 01:36:57 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_flag(const char *fmt, size_t idx, t_spec *spec)
{
	while (ft_strchr("-0# +", fmt[idx]))
	{
		if (fmt[idx] == '-')
			spec->is_minus = true;
		else if (fmt[idx] == '0')
			spec->is_zero = true;
		else if (fmt[idx] == '#')
			spec->is_hash = true;
		else if (fmt[idx] == ' ')
			spec->is_space = true;
		else if (fmt[idx] == '+')
			spec->is_plus = true;
		idx++;
	}
	return (idx);
}

size_t	parse_spec(const char *fmt, size_t i, t_spec *spec)
{
	size_t	idx;

	idx = i + 1;
	idx = get_flag(fmt, idx, spec);
	if (ft_isdigit(fmt[idx]))
		spec->width = ft_atoi(&fmt[idx]);
	while (ft_isdigit(fmt[idx]))
		idx++;
	if (fmt[idx] == '.')
	{
		idx++;
		spec->is_precision = true;
		spec->precision = ft_atoi(&fmt[idx]);
		while (ft_isdigit(fmt[idx]))
			idx++;
	}
	spec->specifier = fmt[idx];
	return (idx + 1);
}
