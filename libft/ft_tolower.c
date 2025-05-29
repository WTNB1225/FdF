/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:58:44 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/25 16:01:47 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%c\n", ft_tolower('a'));
	printf("%c\n", ft_tolower('z'));
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('Z'));
	printf("%c\n", ft_tolower('_'));
}
*/
