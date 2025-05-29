/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:48:07 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:39:24 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*ostr = str;

	while (*str)
		str++;
	return (str - ostr);
}

/*
#include <assert.h>
int main(void)
{
	assert(ft_strlen("hogehoge") == 8);
	assert(ft_strlen("hoge") == 4);
	assert(ft_strlen("") == 0);
}
*/
