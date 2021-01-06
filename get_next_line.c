/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:06:41 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/06 10:38:32 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
									ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free((char*)s1);
	return (str);
}

char	*ft_strdup(const char *src)
{
	char *dst;

	if (!(dst = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strlcpy(dst, (char*)src, ft_strlen(src) + 1);
	return (dst);
}

char	*rem_variable(char **line, char *rem)
{
	char *newline_pointer;

	newline_pointer = NULL;
	if (rem)
		if ((newline_pointer = ft_strchr(rem, '\n')))
		{
			*newline_pointer = '\0';
			*line = ft_strdup(rem);
			ft_strcpy(rem, ++newline_pointer);
		}
		else
		{
			*line = ft_strdup(rem);
			if (rem)
				while (*rem)
					*rem++ = '\0';
		}
	else
		*line = ft_strnew(1);
	return (newline_pointer);
}

void	do_gnl(char **tmp, char **rem, char **newline_p)
{
	*tmp = *rem;
	**newline_p = '\0';
	*rem = ft_strdup(++*newline_p);
	free(*tmp);
}

int		get_next_line(int fd, char **line)
{
	int				bytes_read;
	char			*buf;
	char			*newline_p;
	char			*tmp;
	static char		*rem = NULL;

	if (!line || fd < 0 || BUFFER_SIZE <= 0 ||
	(!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	if (read(fd, buf, 0) == -1)
	{
		free(buf);
		return (-1);
	}
	newline_p = rem_variable(line, rem);
	while (!newline_p && (bytes_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes_read] = '\0';
		if ((newline_p = ft_strchr(buf, '\n')))
			do_gnl(&tmp, &rem, &newline_p);
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (newline_p ? 1 : 0);
}
