/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:06:43 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/06 10:23:00 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char		*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t		ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t j;
	size_t i;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (!src || !dst || size == 0)
		return (i);
	while (src[j] != '\0' && j < (size - 1))
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

char		*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (*str == c)
		return ((char*)str);
	while (*str)
	{
		str++;
		if (*str == c)
			return ((char*)str);
	}
	return (NULL);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
