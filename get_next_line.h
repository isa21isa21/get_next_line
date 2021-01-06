/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquickbe <cquickbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:13:51 by cquickbe          #+#    #+#             */
/*   Updated: 2021/01/06 10:38:35 by cquickbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dst, char *src);
int		get_next_line(int fd, char **line);

#endif
