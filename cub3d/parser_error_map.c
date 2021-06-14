/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void 	parsing_inside_map_er(t_cub *cub, int y, int x)
{
	if (cub->worldmap[y][x + 1] == ' '
		|| cub->worldmap[y][x + 1] == '\n'
		|| cub->worldmap[y][x + 1] == '\0')
		error_map("open map");
	if (cub->worldmap[y][x - 1] == ' '
		|| cub->worldmap[y][x - 1] == '\n'
		|| cub->worldmap[y][x - 1] == '\0')
		error_map("open map");
	if (cub->worldmap[y + 1][x] == ' '
		|| cub->worldmap[y + 1][x] == '\n'
		|| cub->worldmap[y + 1][x] == '\0')
		error_map("open map");
	if (cub->worldmap[y - 1][x] == ' '
		|| cub->worldmap[y - 1][x] == '\n'
		|| cub->worldmap[y - 1][x] == '\0')
		error_map("open map");
}

void 	parser_map_er_help(t_cub *cub, int y, int x)
{
	if (cub->worldmap[y][x] != '\n' && cub->worldmap[y][x] != '\0'
		&& cub->worldmap[y][x] != 'S' && cub->worldmap[y][x] != 'E'
		&& cub->worldmap[y][x] != 'W' && cub->worldmap[y][x] != 'N'
		&& cub->worldmap[y][x] != '1' && cub->worldmap[y][x] != '0'
		&& cub->worldmap[y][x] != '2' && cub->worldmap[y][x] != ' ')
		error_map("wrong character");
	if ((y == 0 && (cub->worldmap[y][x] != '1' && (cub->worldmap[y + 1][x] !=' '
			&& cub->worldmap[y + 1][x] != '1'))) || (y == 0
		&& (cub->worldmap[y][x] == '0' || cub->worldmap[y][x] == '2'
		|| cub->worldmap[y][x] == 'N' || cub->worldmap[y][x] == 'E'
		|| cub->worldmap[y][x] == 'W' || cub->worldmap[y][x] == 'S')))
		error_map("on first line on map something wrong");
	if ((y == cub->ht - 1 && (cub->worldmap[y][x] != '1'
			&& (cub->worldmap[y - 1][x] != ' '
			&& cub->worldmap[y - 1][x] != '1')))
		|| (y == cub->ht - 1 && (cub->worldmap[y][x] == '0'
		|| cub->worldmap[y][x] == '2' || cub->worldmap[y][x] == 'N'
		|| cub->worldmap[y][x] == 'E' || cub->worldmap[y][x] == 'W'
		|| cub->worldmap[y][x] == 'S')))
		error_map("on last line on map something wrong");
	if ((x == 0 && (cub->worldmap[y][x] == '0' || cub->worldmap[y][x] == '2'
		|| cub->worldmap[y][x] == 'N' || cub->worldmap[y][x] == 'E'
	|| cub->worldmap[y][x] == 'W' || cub->worldmap[y][x] == 'S')))
		error_map("first character wrong");
}

void 	parser_pos_player(t_cub *cub, int y, int x)
{
	if (cub->worldmap[y][x] == 'S' || cub->worldmap[y][x] == 'E'
		|| cub->worldmap[y][x] == 'W' || cub->worldmap[y][x] == 'N')
	{
		cub->posY = x + 0.5;
		cub->posX = y + 0.5;
		check_dir(cub, cub->worldmap[y][x]);
		cub->dir_flag++;
	}
	if (cub->worldmap[y][x] == '2')
		cub->numSprites++;
}

void	parser_map_er(t_cub *cub)
{
	int	x;
	int	y;

	y = 0;
	cub->dir_flag = 0;
	while (cub->worldmap[y])
	{
		x = 0;
		while (cub->worldmap[y][x])
		{
			parser_map_er_help(cub, y, x);
			if (cub->worldmap[y][x] == '0' || cub->worldmap[y][x] == '2'
				|| cub->worldmap[y][x] == 'S' || cub->worldmap[y][x] == 'E'
				|| cub->worldmap[y][x] == 'W' || cub->worldmap[y][x] == 'N')
			{
				parser_pos_player(cub, y, x);
				parsing_inside_map_er(cub, y, x);
			}
			x++;
		}
		y++;
	}
	if (cub->dir_flag != 1)
		error_map("wrong number of player");
}
