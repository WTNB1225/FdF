/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:37:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 02:43:20 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit_error("Invalid arguments", false);
	read_file(argv[1], &map);
	isometric(&map);
	init_mlx(&map);
	free(map.alt);
	return (0);
}
