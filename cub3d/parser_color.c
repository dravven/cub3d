/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_dot(const char *map, int x)
{
	if (map[x] == ',')
		return (x + 1);
	else
		error_map("wrong resolution");
	return (0);
}

void 	check_color_error(char s, int r, int g, int b)
{
	if (s != '\n' && s != '\0')
		error_map("something else on line");
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		error_map("wrong color");
}

void	parser_color(const char *map, int x, t_cub *cub, char color)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 0;
	b = 0;
	while (map[x] == ' ')
		x++;
	while (ft_isdigit(map[x]))
		r = r * 10 + (map[x++] - 48);
	x = check_dot(map, x);
	while (ft_isdigit(map[x]))
		g = g * 10 + (map[x++] - 48);
	x = check_dot(map, x);
	while (ft_isdigit(map[x]))
		b = b * 10 + (map[x++] - 48);
	while (map[x] == ' ')
		x++;
	check_color_error(map[x], r, g, b);
	if (color == 'f')
		cub->rgb_f = 65536 * r + 256 * g + b;
	if (color == 'c')
		cub->rgb_c = 65536 * r + 256 * g + b;
}
