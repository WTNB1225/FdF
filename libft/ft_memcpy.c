/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 00:28:09 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:01:49 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <string.h>
#include <assert.h>
int	main(void)
{
	char src[] = "hello";
	char d1[6], d2[6];
	memcpy(d1, src, sizeof(src));
	ft_memcpy(d2, src, sizeof(src));
	assert(memcmp(d1, d2, sizeof(src)) == 0);
	memcpy(NULL, src, 0);
	ft_memcpy(NULL, src, 0);
	memcpy(d1, NULL, 0);
	ft_memcpy(d2, NULL, 0);
	memcpy(NULL, NULL, 0);
	ft_memcpy(NULL, NULL, 0);
	// 0 igai segfo
	//memcpy(NULL, NULL, 1);
	//ft_memcpy(NULL, NULL, 1);
	//memcpy(NULL, src, 1);
	//ft_memcpy(NULL, src, 1);
	//memcpy(d1, NULL, 1);
	//ft_memcpy(d2, NULL, 1);
}
*/
