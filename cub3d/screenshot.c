/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void 	ft_bmp_meta(t_cub *cub, unsigned char *buf)
{
	ft_bzero(buf, 54);
	buf[0] = 'B';
	buf[1] = 'M';
	buf[2] = ((cub->width * cub->height * 4 + 54) >> 24);
	buf[3] = ((cub->width * cub->height * 4 + 54) >> 16);
	buf[4] = ((cub->width * cub->height * 4 + 54) >> 8);
	buf[5] = cub->width * cub->height * 4 + 54;
	buf[10] = 54;
	buf[14] = 40;
	buf[18] = cub->width;
	buf[19] = cub->width >> 8;
	buf[20] = cub->width >> 16;
	buf[21] = cub->width >> 24;
	buf[22] = -cub->height;
	buf[23] = -cub->height >> 8;
	buf[24] = -cub->height >> 16;
	buf[25] = -cub->height >> 24;
	buf[26] = 1;
	buf[28] = 32;
}

void	ft_screenshot(t_cub *cub)
{
	unsigned char	buf[54];
	int				fd;
	int				i;
	int				j;

	i = 0;
	fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		error_map("screenshot cant");
	ft_bmp_meta(cub, buf);
	j = 32 / 8 * cub->width;
	write(fd, &buf, 54);
	while (i < cub->height)
	{
		write(fd, &cub->adr[i * cub->line_length], j);
		i++;
	}
	close(fd);
	write(1, "your screenshot!\n", 26);
	exit(1);
}
