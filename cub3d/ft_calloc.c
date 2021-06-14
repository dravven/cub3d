/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	size_t	s;
	char	*new_mem;

	i = 0;
	s = count * size;
	new_mem = malloc(s);
	if (new_mem == NULL)
		return (NULL);
	while (s--)
	{
		new_mem[i] = 0;
		i++;
	}
	return ((void *)new_mem);
}
