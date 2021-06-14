/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_res(t_cub *cub)
{
	int	h;
	int	w;

	cub->moveSpeed = 0.2;
	cub->rotSpeed = 0.08;
	mlx_get_screen_size(cub->mlx, &w, &h);
	if (cub->width > w)
		cub->width = w;
	if (cub->height > h)
		cub->height = h;
}

void 	texbuf_mall(t_cub *cub)
{
	int	i;
	int	j;

	cub->zBuffer = (double *)malloc(sizeof(double) * cub->width);
	i = 0;
	cub->texture = (int **)malloc(sizeof(int *) * 5);
	if (cub->texture == NULL || cub->zBuffer == NULL)
		error_map("can't malloc texture\n");
	while (i < 5)
	{
		cub->texture[i] = (int *)malloc(sizeof(int) * (cub->texHeight
					* cub->texWidth));
		if (cub->texture[i] == NULL)
			error_map("can't malloc texture 2\n");
		i++;
	}
	i = 0;
	j = 0;
	while (i < 5)
	{
		while (j < (cub->texHeight * cub->texWidth))
			cub->texture[i][j++] = 0;
		i++;
	}
}

int	make_map_help(char **map, int y, t_cub *cub)
{
	int	c;
	int	x;

	c = 1;
	while (map[y] && c > 0)
	{
		c = parser_tex(map, y, cub);
		y++;
	}
	while (map[y])
	{
		x = 0;
		while ((map[y][x] == ' ' || map[y][x] == '\n')
			   && map[y][x] != '1' && map[y][x] != '\0')
			x++;
		if (map[y][x] == '1')
			break ;
		y++;
	}
	return (y);
}

void	make_map(t_list **head, int size, t_cub *cub)
{
	char	**map;
	int		i;
	int		y;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	if (map == NULL)
		error_map("can't calloc");
	i = -1;
	y = 0;
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	y = make_map_help(map, y, cub) - 1;
	size_map(map, y, cub);
	cub->worldmap = ft_calloc(cub->ht + 1, sizeof(char *));
	if ((cub->worldmap) == NULL)
		error_map("can't calloc");
	parser_map(map, y, cub);
	parser_map_er(cub);
	sprite_posmall(cub);
	free(map);
}
