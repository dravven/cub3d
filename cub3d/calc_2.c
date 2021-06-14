/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcalc_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	calc_draw(t_cub *cub, int x)
{
	int	y;

	y = cub->drawStart;
	while (y < cub->drawEnd)
	{
		cub->texY = (int)cub->texPos & (cub->texHeight - 1);
		cub->texPos += cub->step;
		cub->color = cub->texture[cub->texNum][cub->texHeight * cub->texY
			+ cub->texX];
		calc_draw_side(cub);
		my_mlx_pixel_put(cub, x, y, cub->color);
		y++;
	}
}

void 	calc_sprites2_help(t_cub *cub, int	texX, int stripe)
{
	int	y;
	int	texY;
	int	d;

	y = cub->drawStartY;
	while (y < cub->drawEndY)
	{
		d = (y - cub->vMoveScreen) * 256 - cub->height * 128
			+ cub->spriteHeight * 128;
		texY = ((d * cub->texHeight) / cub->spriteHeight) / 256;
		cub->color = cub->texture[4][cub->texWidth * texY + texX];
		if ((cub->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(cub, stripe, y, cub->color);
		y++;
	}
}

void 	calc_sprites2(t_cub *cub)
{
	int	stripe;
	int	texX;

	stripe = cub->drawStartX;
	while (stripe < cub->drawEndX)
	{
		texX = (int)((256 * (stripe - (-cub->spriteWidth / 2
							+ cub->spriteScreenX)) * cub->texWidth
					  / cub->spriteWidth) / 256);
		if (cub->transformY > 0 && stripe > 0 && stripe < cub->width
			&& cub->transformY < cub->zBuffer[stripe])
			calc_sprites2_help(cub, texX, stripe);
		stripe++;
	}
}

void 	calc_sprites11(t_cub *cub)
{
	if (cub->drawStartY < 0)
		cub->drawStartY = 0;
	cub->drawEndY = cub->spriteHeight / 2 + cub->height / 2
		+ cub->vMoveScreen;
	if (cub->drawEndY >= cub->height)
		cub->drawEndY = cub->height - 1;
	cub->spriteWidth = (int)fabs((cub->height / cub->transformY)
			/ cub->uDiv);
	cub->drawStartX = -cub->spriteWidth / 2 + cub->spriteScreenX;
	if (cub->drawStartX < 0)
		cub->drawStartX = 0;
	cub->drawEndX = cub->spriteWidth / 2 + cub->spriteScreenX;
	if (cub->drawEndX >= cub->width)
		cub->drawEndX = cub->width - 1;
}

void 	calc_sprite1(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->numSprites)
	{
		cub->spriteX = cub->sprites[cub->spriteOrder[i]].x - cub->posX;
		cub->spriteY = cub->sprites[cub->spriteOrder[i]].y - cub->posY;
		cub->invDet = 1.0 / (cub->planeX * cub->dirY - cub->dirX * cub->planeY);
		cub->transformX = cub->invDet * (cub->dirY * cub->spriteX - cub->dirX
				* cub->spriteY);
		cub->transformY = cub->invDet * (-cub->planeY * cub->spriteX
				+ cub->planeX * cub->spriteY);
		cub->spriteScreenX = (int)((cub->width / 2) * (1 + cub->transformX
					/ cub->transformY));
		cub->vMoveScreen = (int)(cub->vMove / cub->transformY);
		cub->spriteHeight = (int)fabs((cub->height / cub->transformY)
				/ cub->vDiv);
		cub->drawStartY = -cub->spriteHeight / 2 + cub->height / 2
			+ cub->vMoveScreen;
		calc_sprites11(cub);
		calc_sprites2(cub);
		i++;
	}
}
