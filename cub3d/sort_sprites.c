/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	i = 0;
	sprites = (t_pair *)malloc(sizeof(t_pair) * amount);
	while (i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	sort_order(sprites, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
		i++;
	}
	free(sprites);
}
