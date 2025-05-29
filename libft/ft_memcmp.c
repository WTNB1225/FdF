/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:55:37 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/02 13:13:15 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((us1[i] != us2[i]))
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

void test_memcmp(const void *s1, const void *s2, size_t n)
{
    int expected = memcmp(s1, s2, n);
    int actual = ft_memcmp(s1, s2, n);

if ((expected == 0 && actual == 0) || (expected < 0 && actual < 0)
|| (expected > 0 && actual > 0)){
 printf("Passed: memcmp(\"%s\", \"%s\", %zu)\n",
 (const char *)s1, (const char *)s2, n);
    } else {
        printf("Failed: memcmp(\"%s\", \"%s\", %zu)\n",
		(const char *)s1, (const char *)s2, n);
        printf("   Expected: %d, Got: %d\n", expected, actual);
    }
}

int main()
{
    test_memcmp("abc", "abc", 3);        // same
    test_memcmp("abc", "abd", 3);        // last char different
    test_memcmp("abc", "abcde", 3);      // only first 3 compared
    test_memcmp("abc", "ab", 2);         // partial match
    test_memcmp("abc", "xyz", 1);        // first char different
    test_memcmp("abc", "abc", 0);        // zero-length
    test_memcmp("abc", "ABC", 3);        // case difference
    test_memcmp("\x01\x02\x03", "\x01\x02\x04", 3); // binary data
	//printf("%d\n", ft_memcmp("c", "d", 1));
    return 0;
}
*/
