/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:49:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 22:53:23 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_tile_size(t_map *map)
{
	int	tile_size_by_width;
	int	tile_size_by_height;

	tile_size_by_width = WINDOW_WIDTH / (map->max_width - map->min_width);
	tile_size_by_height = WINDOW_HEIGHT / (map->max_height - map->min_height);
	if (tile_size_by_width < tile_size_by_height)
		return (tile_size_by_width);
	else
		return (tile_size_by_height);
}

void	set_max(t_map *map)
{
	size_t	i;
	size_t	j;

	map->min_width = map->coord_x[0];
	map->max_width = map->coord_x[0];
	map->min_height = map->coord_y[0];
	map->max_height = map->coord_y[0];
	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->max_width < map->coord_x[map->width * j + i])
				map->max_width = map->coord_x[map->width * j + i];
			if (map->min_width > map->coord_x[map->width * j + i])
				map->min_width = map->coord_x[map->width * j + i];
			if (map->min_height > map->coord_y[map->width * j + i])
				map->min_height = map->coord_y[map->width * j + i];
			if (map->max_height < map->coord_y[map->width * j + i])
				map->max_height = map->coord_y[map->width * j + i];
			i++;
		}
		j++;
	}
}
