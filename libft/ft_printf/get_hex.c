/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:54:05 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/13 01:34:32 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_hex(unsigned int n)
{
	const char		*hex_table = "0123456789abcdef";
	unsigned int	tmp;
	size_t			hex_len;
	char			*hex_ptr;

	tmp = n;
	hex_len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		hex_len++;
		tmp /= 16;
	}
	hex_ptr = (char *)malloc(sizeof(char) * (hex_len + 1));
	if (hex_ptr == NULL)
		return (NULL);
	hex_ptr[hex_len] = '\0';
	while (n > 0)
	{
		hex_ptr[--hex_len] = hex_table[n % 16];
		n /= 16;
	}
	return (hex_ptr);
}

char	*get_upper_hex(unsigned int n)
{
	const char		*hex_table = "0123456789ABCDEF";
	unsigned int	tmp;
	size_t			hex_len;
	char			*hex_ptr;

	tmp = n;
	hex_len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		hex_len++;
		tmp /= 16;
	}
	hex_ptr = (char *)malloc(sizeof(char) * (hex_len + 1));
	if (hex_ptr == NULL)
		return (NULL);
	hex_ptr[hex_len] = '\0';
	while (n > 0)
	{
		hex_ptr[--hex_len] = hex_table[n % 16];
		n /= 16;
	}
	return (hex_ptr);
}

char	*get_hex_ptr(uintptr_t n)
{
	const char	*hex_table = "0123456789abcdef";
	uintptr_t	tmp;
	size_t		hex_len;
	size_t		i;
	char		*hex_ptr;

	tmp = n;
	hex_len = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (tmp > 0)
	{
		hex_len++;
		tmp /= 16;
	}
	hex_ptr = (char *)ft_calloc(hex_len + 1, sizeof(char));
	if (hex_ptr == NULL)
		return (NULL);
	i = hex_len - 1;
	while (n > 0)
	{
		hex_ptr[i--] = hex_table[n % 16];
		n /= 16;
	}
	return (hex_ptr);
}
