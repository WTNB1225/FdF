/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:02:33 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:32:17 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	const size_t	little_len = ft_strlen(little);

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		if (little[0] == big[i])
		{
			while (j < little_len && i + j < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
			if (j == little_len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>

void test_strnstr(const char *haystack, const char *needle, size_t len) {
    char *expected = strnstr(haystack, needle, len);
    char *actual = ft_strnstr(haystack, needle, len);

if (expected == actual || (expected && actual
&& strcmp(expected, actual) == 0)) {
    printf("Passed: strnstr(\"%s\", \"%s\", %zu)\n", haystack, needle, len);
	printf("%s\n",  expected);
	printf("%s\n",  actual);
} else {
    printf("Failed: strnstr(\"%s\", \"%s\", %zu)\n", haystack, needle, len);
    printf("   Expected: %s\n", expected ? expected : "NULL");
    printf("   Got     : %s\n", actual ? actual : "NULL");
}
}

int main() {
    test_strnstr("hello world", "world", 11);    // 見つかる
    test_strnstr("hello world", "world", 5);     // 見つからない
    test_strnstr("abcdef", "def", 6);            // 後半にあり
    test_strnstr("abcdef", "def", 3);            // lenが短すぎて見つからない
    test_strnstr("abcdef", "", 6);               // 空needle → haystackを返す
    test_strnstr("", "abc", 3);                  // haystackが空
    test_strnstr("", "", 0);                     // 両方空
    test_strnstr(NULL, "\0", 1);                     // 両方空
    test_strnstr("abcabcabc", "cab", 8);         // 途中に出現するパターン
    test_strnstr("abcabcabc", "abc", 2);         // 長さが足りない → NULL
    test_strnstr("abcabcabc", "abcabcabc", 9);         // 長さが足りない → NULL
    test_strnstr("abbbcdefg", "bbc", 20);
    return 0;
}
*/
