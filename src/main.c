/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:37:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 00:18:06 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	map;
	int		min_width;
	int		max_width;
	int		min_heght;
	int		max_height;

	if (argc != 2)
		exit_error("Invalid arguments", false);
	min_width = 0;
	max_width = 0;
	min_heght = 0;
	max_height = 0;
	read_file(argv[1], &map);
	isometric(&map, &min_width, &max_width, &min_heght, &max_height);
	init_mlx(&map);
	free(map.alt);
	return (0);
}
