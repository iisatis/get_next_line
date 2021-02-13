/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:05:26 by pflorent          #+#    #+#             */
/*   Updated: 2021/02/06 15:15:05 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_alloc(size_t size)
{
	char	*s;

	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	s[0] = '\0';
	return (s);
}

static char	*get_line(char **buff, int *n)
{
	int		l;
	char	*trim;
	char	*line;

	if ((l = ft_chr(*buff, '\n')) == -1)
		*n = 0;
	if (*n == 0)
		l = ft_len(*buff);
	if ((line = ft_ndup(*buff, l)) == NULL)
		*n = -1;
	l++;
	if (*n == 1)
		if ((trim = ft_ndup(&(buff[0][l]), ft_len(&(buff[0][l])))) == NULL)
		{
			free(line);
			*n = -1;
		}
	if (*n == 1)
	{
		free(*buff);
		*buff = trim;
	}
	return (line);
}

int			get_next_line(int fd, char **line)
{
	static char		*buf;
	char			tmp[BUFFER_SIZE + 1];
	long			end_b;
	int				n;

	n = 1;
	if ((fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, tmp, 0) < 0) ||
		(buf == NULL && (buf = ft_alloc(0)) == NULL))
		return (-1);
	while (ft_chr(buf, '\n') == -1 && (end_b = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[end_b] = '\0';
		if ((buf = ft_join(&buf, tmp)) == NULL)
		{
			free(buf);
			return (-1);
		}
	}
	*line = get_line(&buf, &n);
	if (n != 1)
		ft_reset(&buf);
	return (n);
}
