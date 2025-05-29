/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:31:36 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:35:59 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//#include <assert.h>
//int main(void)
//{
//  assert(ft_isdigit('0') == 1);
//  assert(ft_isdigit('9') == 1);
//  assert(ft_isdigit('a') == 0);
//  assert(ft_isdigit('\n') == 0);
//}
