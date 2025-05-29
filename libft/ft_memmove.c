/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:19:05 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:10:37 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ucdest;
	unsigned char	*ucsrc;

	if ((dest == NULL && src == NULL) || (dest == NULL && n == 0)
		|| (src == NULL && n == 0))
		return (NULL);
	i = 0;
	ucdest = (unsigned char *)dest;
	ucsrc = (unsigned char *)src;
	if (ucdest < ucsrc)
	{
		while (i < n)
		{
			ucdest[i] = ucsrc[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			ucdest[n] = ucsrc[n];
	}
	return (ucdest);
}

/*
#include <assert.h>
#include <string.h>
int main(void)
{
	char data[] = "ABCDE";
	memmove(data + 1, data, 3);
	printf("%s\n", data);
	char data2[] = "ABCDE";
	ft_memmove(data2 + 1, data2, 3);
	printf("%s\n", data2);
	memmove(NULL, NULL, 0);
	memmove(data, NULL, 0);
	memmove(NULL, data, 0);
	ft_memmove(NULL, NULL, 0);
	ft_memmove(data, NULL, 0);
	ft_memmove(NULL, data, 0);
	//memmove(NULL, NULL, 1);
	//memmove(data, NULL, 1);
	//memmove(NULL, data, 1);
	//ft_memmove(NULL, NULL, 1);
	//ft_memmove(data, NULL, 1);
	//ft_memmove(NULL, data, 1);
}
*/
