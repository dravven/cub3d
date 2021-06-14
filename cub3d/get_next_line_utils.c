/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

size_t	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	weeknd(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_2(char *src)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[len] != '\0' && src[len] != '\n')
		len++;
	if (!src[len])
	{
		free(src);
		return (0);
	}
	dest = malloc(sizeof(char) * ((ft_strlenn(src) - i) + 1));
	if (dest == NULL)
		return (0);
	len++;
	while (src[len] != '\0')
		dest[i++] = src[len++];
	dest[i] = '\0';
	free(src);
	return (dest);
}
