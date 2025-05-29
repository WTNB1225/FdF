/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:03:44 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/28 18:33:21 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

/*
#include <assert.h>
int main(void)
{
	assert(ft_isprint('A') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('Z') == 1);
	assert(ft_isprint('z') == 1);
	assert(ft_isprint('\0') == 0);
}
*/
