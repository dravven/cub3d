/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtymor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:20:52 by dtymor            #+#    #+#             */
/*   Updated: 2021/05/03 18:27:48 by dtymor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*ft_strdup_1(char *src)
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
	dest = (char *)malloc(sizeof(*dest) * len + 1);
	if (dest == NULL)
		return (0);
	while (src[i] != '\0' && src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoinn(char const *s1, char const *s2)
{
	unsigned int	i;
	int				j;
	char			*str;

	i = ft_strlenn(s1) + ft_strlenn(s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[j])
			str[i++] = s1[j++];
	j = 0;
	if (s2)
		while (s2[j])
			str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

int	check_error(int fd, char **line, char *buff)
{
	if (buff == NULL)
		return (-1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	return (1);
}

int	ft_byt_rd(int byt_rd)
{
	if (byt_rd == 0)
		return (0);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*end;
	int				byt_rd;
	char			*trash;

	byt_rd = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(check_error(fd, line, buff)))
		return (-1);
	while (byt_rd != 0 && !(weeknd(end)))
	{
		byt_rd = read(fd, buff, BUFFER_SIZE);
		if (byt_rd < 0)
			return (-1);
		buff[byt_rd] = '\0';
		trash = end;
		end = ft_strjoinn(end, buff);
		if (end == NULL)
			return (-1);
		free(trash);
	}
	free(buff);
	*line = ft_strdup_1(end);
	end = ft_strdup_2(end);
	return (ft_byt_rd(byt_rd));
}
