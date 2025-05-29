/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:37:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/30 00:09:39 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_error("Invalid arguments", false);
	read_file(argv[1], &map);
	printf("%zu\n", map.height);
	printf("%zu\n", map.width);
	size_t	i = 0;
	while (i < map.height * map.width)
	{
		printf("%d ", map.alt[i]);
		i++;
	}
	free(map.alt);
	return (0);
}
