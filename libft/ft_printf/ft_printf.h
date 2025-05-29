/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:02:02 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 23:44:37 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include "../libft.h"

typedef struct s_spec
{
	bool	is_minus;
	bool	is_zero;
	bool	is_plus;
	bool	is_space;
	bool	is_hash;
	size_t	width;
	size_t	precision;
	bool	is_precision;
	char	specifier;
}	t_spec;

int		ft_printf(const char *format, ...);
t_spec	*init_spec(void);
t_spec	*reset_spec(t_spec *spec);
size_t	parse_spec(const char *fmt, size_t i, t_spec *spec);
int		print_spec(t_spec *spec, va_list ap);
size_t	print_char(char c, t_spec *spec);
size_t	print_str(char *str, t_spec *spec);
size_t	print_int(int n, t_spec *spec);
int		print_u(unsigned int n, t_spec *spec);
int		print_x(unsigned int n, t_spec *spec);
int		print_upper_x(unsigned int n, t_spec *spec);
int		print_p(void *ptr, t_spec *spec);
size_t	get_digit(int n);
size_t	get_abs(int n);
char	*ft_stoa(size_t n);
char	*get_hex(unsigned int n);
char	*get_upper_hex(unsigned int n);
size_t	print_lower_hex(unsigned int num);
size_t	print_upper_hex(unsigned int num);
size_t	print_address(uintptr_t ptr);
char	*get_hex_ptr(uintptr_t n);
size_t	int_get_print_len(t_spec *spec, size_t print_len, int n);
size_t	int_print_space_or_zero(t_spec *spec, int n, size_t pad_len, char *str);
size_t	print_zero_or_space(t_spec *spec, size_t pad_len);
size_t	unsigned_print_zero_or_space(t_spec *spec, size_t pad_len);
size_t	zero_and_precision_zero(t_spec *spec, char *n_str);
size_t	print_pad(size_t pad_len);
size_t	putchar_fd(char c, int fd);
size_t	putstr_fd(char *s, int fd);
size_t	putendl_fd(char *s, int fd);
size_t	putnbr_fd(int num, int fd);
#endif
