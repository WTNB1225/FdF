/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 20:34:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 21:09:03 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t	putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

size_t	putendl_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
	return (len + 1);
}

size_t	putnbr_fd(int n, int fd)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		len++;
		n *= -1;
	}
	if (n >= 10)
	{
		len += putnbr_fd(n / 10, fd);
	}
	putchar_fd((n % 10) + '0', fd);
	return (len + 1);
}
