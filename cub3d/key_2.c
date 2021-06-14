/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_left(t_cub *cub)
{
	if (cub->worldmap[(int)(cub->posX - cub->dirY * cub->rotSpeed)][
				(int)(cub->posY)] != '1')
		cub->posX -= cub->dirY * cub->rotSpeed;
	if (cub->worldmap[(int)(cub->posX)][(int)(cub->posY + cub->dirX
						 * cub->rotSpeed)] != '1')
		cub->posY += cub->dirX * cub->rotSpeed;
}

void	move_right(t_cub *cub)
{
	if (cub->worldmap[(int)(cub->posX + cub->dirY * cub->rotSpeed)][
				(int)(cub->posY)] != '1')
		cub->posX += cub->dirY * cub->rotSpeed;
	if (cub->worldmap[(int)(cub->posX)][(int)(cub->posY - cub->dirX
						* cub->rotSpeed)] != '1')
		cub->posY -= cub->dirX * cub->rotSpeed;
}
