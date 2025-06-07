/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:00 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/05 01:47:17 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coord(t_map *map)
{
	int		j;
	int		i;
	float	*coord_x;
	float	*coord_y;
	int		idx;

	coord_x = (float *)malloc(sizeof(float) * (map->width * map->height));
	coord_y = (float *)malloc(sizeof(float) * (map->width * map->height));
	if (!coord_x || !coord_y)
		exit_error("Failed to allocate memory", false);
	j = 0;
	while (j < (int)map->height)
	{
		i = 0;
		while (i < (int)map->width)
		{
			idx = map->width * j + i;
			coord_x[idx] = (i + j) * cos(get_rad(30));
			coord_y[idx] = (j - i) * sin(get_rad(30)) - map->alt[idx];
			i++;
		}
		j++;
	}
	map->coord_x = coord_x;
	map->coord_y = coord_y;
}

void	isometric(t_map *map)
{
	int		tile;
	size_t	i;
	size_t	j;
	long long int		offset_x;
	long long int		offset_y;
	size_t	idx;

	j = 0;
	set_coord(map);
	set_max(map);
	tile = get_tile_size(map);
	//ft_printf("min_width: %d, max_width: %d\n", map->min_width, map->max_width);
	//ft_printf("min_height: %d, max_height: %d\n", map->min_height, map->max_height);
	offset_x = (WINDOW_WIDTH / 2) - (map->max_width + map->min_width) * tile / 2;
	offset_y = (WINDOW_HEIGHT / 2) - (map->max_height + map->min_height) * tile / 2;
	//ft_printf("offset_x: %d, offset_y: %d, tile: %d\n", offset_x, offset_y, tile);
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			idx = map->width * j + i;
			//ft_printf("[x: %d, y: %d]\n", map->coord_x[idx], map->coord_y[idx]);
			map->coord_x[idx] = map->coord_x[idx] * tile + offset_x;
			map->coord_y[idx] = map->coord_y[idx] * tile + offset_y ;
			//ft_printf("[x: %d, y: %d]\n", map->coord_x[idx], map->coord_y[idx]);
			i++;
		}
		j++;
	}
}
