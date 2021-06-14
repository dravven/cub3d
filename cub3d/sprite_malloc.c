/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sprite_mall(t_cub *cub)
{
	cub->sprites = (t_sprite *)malloc(sizeof(t_sprite) * cub->numSprites);
	if (!cub->sprites)
		error_map("can't malloc\n");
	cub->spriteOrder = (int *)malloc(sizeof(int) * cub->numSprites);
	if (!cub->spriteOrder)
		error_map("can't malloc\n");
	cub->spriteDistance = (double *)malloc(sizeof(double) * cub->numSprites);
	if (!cub->spriteDistance)
		error_map("can't malloc\n");
}

void	sprite_posmall(t_cub *cub)
{
	int			x;
	int			y;
	int			j;
	t_sprite	spr;

	y = 0;
	j = 0;
	sprite_mall(cub);
	while (cub->worldmap[y])
	{
		x = 0;
		while (cub->worldmap[y][x])
		{
			if (cub->worldmap[y][x] == '2')
			{
				spr.y = x + 0.5;
				spr.x = y + 0.5;
				cub->sprites[j] = spr;
				j++;
			}
			x++;
		}
		y++;
	}
}
