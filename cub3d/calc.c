/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calc_sprites(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->numSprites)
	{
		cub->spriteOrder[i] = i;
		cub->spriteDistance[i] = ((cub->posX - cub->sprites[i].x)
				* (cub->posX - cub->sprites[i].x)
				+ (cub->posY - cub->sprites[i].y)
				* (cub->posY - cub->sprites[i].y));
		i++;
	}
	sortSprites(cub->spriteOrder, cub->spriteDistance, cub->numSprites);
	calc_sprite1(cub);
}

void	calc_sid(t_cub *cub)
{
	calc_side(cub);
	calc_hit(cub);
	if (cub->side == 0)
		cub->perpWallDist = (cub->mapX - cub->posX + (1 - cub->stepX) / 2)
			/ cub->rayDirX;
	else
		cub->perpWallDist = (cub->mapY - cub->posY + (1 - cub->stepY) / 2)
			/ cub->rayDirY;
	cub->lineHeight = (int)(cub->height / cub->perpWallDist);
	cub->drawStart = -cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawStart < 0)
		cub->drawStart = 0;
	cub->drawEnd = cub->lineHeight / 2 + cub->height / 2;
	if (cub->drawEnd >= cub->height)
		cub->drawEnd = cub->height - 1;
	if (cub->worldmap[cub->mapX][cub->mapY] == '1')
		cub->texNum = 1;
	else if (cub->worldmap[cub->mapX][cub->mapY] == '0')
		cub->texNum = 0;
	if (cub->side == 0)
		cub->wallX = cub->posY + cub->perpWallDist * cub->rayDirY;
	else
		cub->wallX = cub->posX + cub->perpWallDist * cub->rayDirX;
}

void	calc_help(t_cub *cub)
{
	if (cub->side == 0 && cub->rayDirX > 0)
		cub->texX = cub->texWidth - cub->texX - 1;
	if (cub->side == 1 && cub->rayDirY < 0)
		cub->texX = cub->texWidth - cub->texX - 1;
	cub->step = 1.0 * cub->texHeight / cub->lineHeight;
	cub->texPos = (cub->drawStart - cub->height / 2 + cub->lineHeight / 2)
		* cub->step;
}

void	calc(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < cub->width)
	{
		cub->cameraX = 2 * x / (double)cub->width - 1;
		cub->rayDirX = cub->dirX + cub->planeX * cub->cameraX;
		cub->rayDirY = cub->dirY + cub->planeY * cub->cameraX;
		cub->mapX = (int)cub->posX;
		cub->mapY = (int)cub->posY;
		cub->deltaDistX = fabs(1 / cub->rayDirX);
		cub->deltaDistY = fabs(1 / cub->rayDirY);
		cub->hit = 0;
		calc_sid(cub);
		cub->wallX -= floor(cub->wallX);
		cub->texX = (int)(cub->wallX * (double)cub->texWidth);
		calc_help(cub);
		calc_draw(cub, x);
		cub->zBuffer[x] = cub->perpWallDist;
		x++;
	}
	if (cub->numSprites > 0)
		calc_sprites(cub);
}
