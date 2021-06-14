/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	key_forward(t_cub *cub)
{
	if (cub->worldmap[(int)(cub->posX + cub->dirX * cub->moveSpeed)][(int)
			(cub->posY)] != '1')
		cub->posX += cub->dirX * cub->moveSpeed;
	if (cub->worldmap[(int)(cub->posX)][(int)(cub->posY + cub->dirY
						* cub->moveSpeed)] != '1')
		cub->posY += cub->dirY * cub->moveSpeed;
}

void	key_backward(t_cub *cub)
{
	if (cub->worldmap[(int)(cub->posX - cub->dirX * cub->moveSpeed)][(int)
			(cub->posY)] != '1')
		cub->posX -= cub->dirX * cub->moveSpeed;
	if (cub->worldmap[(int)(cub->posX)][(int)(cub->posY - cub->dirY
						* cub->moveSpeed)] != '1')
		cub->posY -= cub->dirY * cub->moveSpeed;
}

void	key_left(t_cub *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(-cub->rotSpeed) - cub->dirY
		* sin(-cub->rotSpeed);
	cub->dirY = oldDirX * sin(-cub->rotSpeed) + cub->dirY * cos(-cub->rotSpeed);
	oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(-cub->rotSpeed)
		- cub->planeY * sin(-cub->rotSpeed);
	cub->planeY = oldPlaneX * sin(-cub->rotSpeed)
		+ cub->planeY * cos(-cub->rotSpeed);
}

void	key_right(t_cub *cub)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub->dirX;
	cub->dirX = cub->dirX * cos(cub->rotSpeed) - cub->dirY * sin(cub->rotSpeed);
	cub->dirY = oldDirX * sin(cub->rotSpeed) + cub->dirY * cos(cub->rotSpeed);
	oldPlaneX = cub->planeX;
	cub->planeX = cub->planeX * cos(cub->rotSpeed) - cub->planeY
		* sin(cub->rotSpeed);
	cub->planeY = oldPlaneX * sin(cub->rotSpeed)
		+ cub->planeY * cos(cub->rotSpeed);
}

int	key_press(int key, t_cub *cub)
{
	if (key == 13)
		key_forward(cub);
	if (key == 1)
		key_backward(cub);
	if (key == 124)
		key_left(cub);
	if (key == 0)
		move_left(cub);
	if (key == 2)
		move_right(cub);
	if (key == 123)
		key_right(cub);
	if (key == 53)
		exit(0);
	return (1);
}
