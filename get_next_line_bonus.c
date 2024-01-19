/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:32:43 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 18:37:55 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stddef.h>

int	fill_buffer(int fd, char **str)
{
	int		rc;
	char	*tmp;
	char	buff[101];

	rc = 1;
	while (rc && !ft_strchr(*str, '\n'))
	{
		rc = read(fd, buff, 100);
		if (rc <= 0)
			return (rc);
		buff[rc] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
	}
	return (rc);
}

char	*set_line(char *line)
{
	char	*tmp;
	size_t	len;

	len = 0;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\n'))
	{
		while (line[len] != '\n')
			len++;
		tmp = ft_substr(line, 0, len + 1);
		return (tmp);
	}
	return (line);
}

char	*set_remainder(char *remainder)
{
	char	*tmp;
	size_t	len;

	len = 0;
	if (!remainder)
		return (NULL);
	if (ft_strchr(remainder, '\n'))
	{
		while (remainder[len] != '\n')
			len++;
		if (!remainder[len + 1])
		{
			free(remainder);
			return (NULL);
		}
		tmp = remainder;
		tmp = ft_strdup(&tmp[len + 1]);
		free (remainder);
		return (tmp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	if (fill_buffer(fd, &remainder) <= 0 && !remainder)
		return (NULL);
	if (remainder && !ft_strchr(remainder, '\n'))
	{
		line = remainder;
		remainder = NULL;
		return (line);
	}
	line = set_line(remainder);
	remainder = set_remainder(remainder);
	return (line);
}
