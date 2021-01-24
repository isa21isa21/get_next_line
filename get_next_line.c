/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:06:41 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/24 14:12:34 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_return(char *buf)
{
	if (buf)
		free(buf);
	return (-1);
}

int			ft_return_buf(char *n_p, char *buf)
{
	free(buf);
	if (n_p != NULL)
		return (1);
	else
		return (0);
}

static char	*ft_do_gnl(char *line, char *buf)
{
	char *lks;

	lks = line;
	if (!(line = ft_strjoin(line, buf)))
		return (NULL);
	free(lks);
	return (line);
}

static char	*ft_rem_var(char **rem, char **line)
{
	char *n_p;
	char *lks;

	n_p = NULL;
	if (*rem)
	{
		if ((n_p = ft_strchr(*rem, '\n')))
		{
			*n_p = '\0';
			*line = ft_strdup(*rem);
			lks = *rem;
			*rem = ft_strdup(++n_p);
			free(lks);
		}
		else
		{
			*line = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (n_p);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*n_p;
	int			b_read;
	static char	*rem = NULL;

	buf = NULL;
	if (!line || fd < 0 || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1))
	|| (read(fd, buf, 0) < 0))
		return (ft_return(buf));
	n_p = ft_rem_var(&rem, line);
	while (!n_p && (b_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (b_read == -1)
			return (ft_return(buf));
		buf[b_read] = '\0';
		if ((n_p = ft_strchr(buf, '\n')))
		{
			*n_p = '\0';
			if (!(rem = ft_strdup(++n_p)))
				return (ft_return(buf));
		}
		if (!(*line = ft_do_gnl(*line, buf)))
			return (ft_return(buf));
	}
	return (ft_return_buf(n_p, buf));
}
