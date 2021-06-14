/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (0);
	while (string1[i] == string2[i] && string1[i] != '\0' && num - 1 > i)
		i++;
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}

void 	check_dir_1(t_cub *cub, char s)
{
	if (s == 'N')
	{
		cub->dirX = -1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = 0.66;
	}
	else if (s == 'E')
	{
		cub->dirX = 0;
		cub->dirY = 1;
		cub->planeX = 0.66;
		cub->planeY = 0;
	}
}

void	check_dir(t_cub *cub, char s)
{
	check_dir_1(cub, s);
	if (s == 'S')
	{
		cub->dirX = 1;
		cub->dirY = 0;
		cub->planeX = 0;
		cub->planeY = -0.66;
	}
	else if (s == 'W')
	{
		cub->dirX = 0;
		cub->dirY = -1;
		cub->planeX = -0.66;
		cub->planeY = 0;
	}
}

void	load_image_png(t_cub *info, int *texture, char *path)
{
	int	y;
	int	x;

	y = 0;
	info->img = mlx_png_file_to_image(info->mlx, path, &info->img_width,
			&info->img_height);
	info->adr = mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
	info->addr = (int *)mlx_get_data_addr(info->img, &info->bits_per_pixel,
			&info->line_length, &info->endian);
	while (y < info->img_height)
	{
		x = 0;
		while (x < info->img_width)
		{
			texture[info->img_width * y + x] = info->addr[info->img_width
				* y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, info->img);
}

void	load_texture(t_cub *info)
{
	load_image_png(info, info->texture[0], info->p_north);
	load_image_png(info, info->texture[1], info->p_east);
	load_image_png(info, info->texture[2], info->p_west);
	load_image_png(info, info->texture[3], info->p_south);
	load_image_png(info, info->texture[4], info->sprite);
}
