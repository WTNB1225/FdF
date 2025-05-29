/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:40:22 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:35:46 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*
#include <assert.h>
int main(void)
{
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('Z') == 1);
	assert(ft_isalpha('z') == 1);
	assert(ft_isalpha(' ') == 0);
	assert(ft_isalpha('\t') == 0);
}
*/
