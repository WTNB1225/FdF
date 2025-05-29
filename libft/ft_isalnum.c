/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:48:54 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:36:26 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

/*
#include <assert.h>
int main(void)
{
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('Z') == 1);
	assert(ft_isalnum('z') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum(' ') == 0);
	assert(ft_isalnum('\t') == 0);
}
*/
