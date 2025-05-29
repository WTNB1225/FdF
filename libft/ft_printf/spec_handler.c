/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 00:07:08 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/13 01:36:44 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*init_spec(void)
{
	t_spec	*spec;

	spec = (t_spec *)malloc(sizeof(t_spec));
	if (spec == NULL)
		return (NULL);
	spec->is_zero = false;
	spec->is_minus = false;
	spec->is_plus = false;
	spec->is_hash = false;
	spec->is_space = false;
	spec->width = 0;
	spec->precision = 0;
	spec->is_precision = false;
	spec->specifier = ' ';
	return (spec);
}

t_spec	*reset_spec(t_spec *spec)
{
	spec->is_zero = false;
	spec->is_minus = false;
	spec->is_plus = false;
	spec->is_hash = false;
	spec->is_space = false;
	spec->width = 0;
	spec->precision = 0;
	spec->is_precision = false;
	spec->specifier = ' ';
	return (spec);
}
