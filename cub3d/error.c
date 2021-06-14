/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	cube_loop(t_cub *cub)
{
	cub->img = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->addr = (int *)mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			&cub->line_length, &cub->endian);
	cub->adr = mlx_get_data_addr(cub->img, &cub->bits_per_pixel,
			 &cub->line_length, &cub->endian);
	draw_fc(cub);
	calc(cub);
	if (cub->save == 1)
		ft_screenshot(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	mlx_destroy_image(cub->mlx, cub->img);
	return (1);
}

void	draw_fc(t_cub *cub)
{
	int	x;
	int	i;

	x = 0;
	while (x <= cub->width)
	{
		i = 0;
		while (i <= cub->height / 2)
		{
			my_mlx_pixel_put(cub, x, i, cub->rgb_f);
			i++;
		}
		x++;
	}
	x = 0;
	while (x <= cub->width)
	{
		i = cub->height / 2;
		while (i <= cub->height - 2)
		{
			my_mlx_pixel_put(cub, x, i, cub->rgb_c);
			i++;
		}
		x++;
	}
}

void	error_map(char *str)
{
	printf("%s", str);
	exit(3);
}

void	error(char *str, char c)
{
	int	buffer[1];
	int	fd;
	int	file_er;

	fd = open(str, O_RDONLY);
	file_er = read(fd, buffer, 0);
	if (fd < 0)
	{
		printf("can't open tex %c", c);
		exit(2);
	}
	if (file_er < 0)
	{
		printf("can't read tex %c", c);
		exit(2);
	}
	else
		close(fd);
}

void 	initilaze_var(t_cub *cub)
{
	cub->height_f = 0;
	cub->width_f = 0;
	cub->p_flag = 0;
	cub->s_flag = 0;
	cub->e_flag = 0;
	cub->w_flag = 0;
	cub->sp_flag = 0;
	cub->r_flag = 0;
	cub->hit = 0;
	cub->stepX = 0;
	cub->vMoveScreen = 0;
	cub->spriteHeight = 0;
	cub->spriteScreenX = 0;
	cub->numSprites = 0;
	cub->texHeight = 64;
	cub->texWidth = 64;
	cub->uDiv = 1;
	cub->vDiv = 1;
	cub->vMove = 0.0;
	ft_bzero(cub->sprite, 255);
	ft_bzero(cub->p_south, 255);
	ft_bzero(cub->p_west, 255);
	ft_bzero(cub->p_east, 255);
	ft_bzero(cub->p_north, 255);
	ft_bzero(cub->butt, 255);
}
