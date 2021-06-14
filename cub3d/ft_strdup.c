/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	*ft_strdup(const char *str)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = ft_strlen(str);
	dst = (char *)malloc(sizeof(*str) * (total + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < total)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return ((void *)dst);
}
