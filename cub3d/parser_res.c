/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_res.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_win(int i, t_cub *cub)
{
	(void)i;
	(void)cub;
	exit(0);
}

void	parser_res(const char *map, int x, t_cub *cub)
{
	int		i;
	char	butt[255];

	i = 0;
	while (map[x] == ' ')
		x++;
	while (map[x] != '\n' && map[x] != ' ' && map[x] != '\0')
	{
		butt[i++] = map[x++];
		cub->width_f = 1;
	}
	cub->width = ft_atoi(butt);
	while (map[x] == ' ')
		x++;
	i = 0;
	ft_bzero(butt, 255);
	while (map[x] != '\n' && map[x] != ' ' && map[x] != '\0')
	{
		butt[i++] = map[x++];
		cub->height_f = 1;
	}
	cub->height = ft_atoi(butt);
	if (cub->width < 0 || cub->height < 0)
		error_map("wrong res");
}

void	parser_path_tex(char direction, int x, t_cub *cub, const char *map)
{
	int	i;

	i = 0;
	while (map[x] == ' ')
		x++;
	while (map[x] != '\n' && map[x] != ' '
		   && direction == 'n' && map[x] != '\0')
		cub->p_north[i++] = map[x++];
	while (map[x] != ' ' && direction == 's'
		   && map[x] != '\n' && map[x] != '\0')
		cub->p_south[i++] = map[x++];
	while (map[x] != ' ' && direction == 'e'
		   && map[x] != '\n' && map[x] != '\0')
		cub->p_east[i++] = map[x++];
	while (map[x] != ' ' && direction == 'w'
		   && map[x] != '\n' && map[x] != '\0')
		cub->p_west[i++] = map[x++];
	while (map[x] != ' ' && direction == 'S'
		   && map[x] != '\n' && map[x] != '\0')
		cub->sprite[i++] = map[x++];
	x = x - 3;
	if (!(map[x] == 'p' && map[x + 1] == 'n' && map[x + 2] == 'g'))
		error_map("wrong extension of file");
}
