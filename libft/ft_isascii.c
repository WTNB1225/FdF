/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:55:05 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/28 18:32:05 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <assert.h>
int main(void)
{
	assert(ft_isascii('A') == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('Z') == 1);
	assert(ft_isascii('z') == 1);
	assert(ft_isascii(128) == 0);
}
*/
