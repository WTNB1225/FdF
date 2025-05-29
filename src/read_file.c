/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:51:47 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/29 23:13:58 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(const char *filename, t_map *map)
{
	map->height = get_height(filename);
	map->width = get_width(filename);
	map->alt = get_altitude(filename, map);
}
