/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:51:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/06 19:13:39 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(const char *filename, t_map *map)
{
	map->height = get_height(filename);
	map->width = get_width(filename);
	map->alt = get_altitude(filename, map);
	map->color = get_color(filename, map);
}
