/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_and_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	size_map(char **map, int y, t_cub *cub)
{
	int	x;

	cub->ht = 0;
	cub->wd = 0;
	while (map[y])
	{
		x = 0;
		cub->ht++;
		while (map[y][x] != '\n' && map[y][x] != '\0')
			x++;
		if (x > cub->wd)
			cub->wd = x;
		y++;
	}
}

void	parser_map(char **map, int y, t_cub *cub)
{
	int	map_y;

	map_y = 0;
	while (map[y])
		cub->worldmap[map_y++] = map[y++];
	if (y == 0)
		error_map("no map");
}
