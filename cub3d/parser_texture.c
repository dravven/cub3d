/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	parser_tex1_res(const char *map, t_cub *cub, int x)
{
	x++;
	cub->r_flag++;
	parser_res(map, x, cub);
	return (1);
}

int	parser_tex1_color(const char *map, t_cub *cub, char dir, int x)
{
	x++;
	if (dir == 'f')
		cub->f_flag++;
	if (dir == 'c')
		cub->c_flag++;
	parser_color(map, x, cub, dir);
	return (1);
}

int	parser_tex1(const char *map, t_cub *cub, char dir, int x)
{
	x += 2;
	if (dir == 'n')
		cub->p_flag++;
	if (dir == 'e')
		cub->e_flag++;
	if (dir == 's')
		cub->s_flag++;
	if (dir == 'w')
		cub->w_flag++;
	if (dir == 'S')
		cub->sp_flag++;
	parser_path_tex(dir, x, cub, map);
	if (dir == 'n')
		error(cub->p_north, dir);
	if (dir == 'e')
		error(cub->p_east, dir);
	if (dir == 's')
		error(cub->p_south, dir);
	if (dir == 'w')
		error(cub->p_west, dir);
	if (dir == 'S')
		error(cub->sprite, dir);
	return (1);
}

int	returner(const char *map, int x, t_cub *cub)
{
	if (map[x] == 'R')
		return (parser_tex1_res(map, cub, x));
	else if (map[x] == 'N' && map[x + 1] == 'O')
		return (parser_tex1(map, cub, 'n', x));
	else if (map[x] == 'S' && map[x + 1] == 'O')
		return (parser_tex1(map, cub, 's', x));
	else if (map[x] == 'S' && map[x + 1] == ' ')
		return (parser_tex1(map, cub, 'S', x));
	else if (map[x] == 'W' && map[x + 1] == 'E')
		return (parser_tex1(map, cub, 'w', x));
	else if (map[x] == 'E' && map[x + 1] == 'A')
		return (parser_tex1(map, cub, 'e', x));
	else if (map[x] == 'F')
		return (parser_tex1_color(map, cub, 'f', x));
	else if (map[x] == 'C')
		return (parser_tex1_color(map, cub, 'c', x));
	else
		return (0);
}

int	parser_tex(char **map, int y, t_cub *cub)
{
	int	x;

	x = 0;
	while (map[y][x] == ' ')
		x++;
	while (map[y][x] != '\0' && map[y][x] != '\n')
	{
		return (returner(map[y], x, cub));
	}
	return (1);
}
