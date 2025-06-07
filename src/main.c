/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 08:37:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/06 19:13:17 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;
	//t_vars	vars;

	if (argc != 2)
		exit_error("Invalid arguments", false);
	read_file(argv[1], &map);
	for (size_t i = 0; i < map.width * map.height; i++)
		ft_printf("%d ", map.color[i]);
	isometric(&map);
	init_mlx(&map);
	free(map.alt);
	return (0);
}
