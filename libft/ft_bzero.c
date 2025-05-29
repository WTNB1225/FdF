/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:08:36 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:55:48 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*
#include <string.h>
#include <assert.h>
int main(void)
{
	char b1[5], b2[5];
	bzero(b1, sizeof(b1));
	ft_bzero(b2, sizeof(b2));
	assert(memcmp(b1, b2, sizeof(b1)) == 0);
	bzero(NULL, (size_t)0);
	ft_bzero(NULL, (size_t)0);
	// segmentation fault expect n equal 0
	//bzero(NULL, 1);
	//ft_bzero(NULL, 1);
}
*/
