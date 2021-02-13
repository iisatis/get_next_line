/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:05:47 by pflorent          #+#    #+#             */
/*   Updated: 2021/01/15 17:05:50 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_reset(char **buf)
{
	free(*buf);
	*buf = NULL;
}

size_t	ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_ndup(const char *src, size_t len)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_chr(const char *str, char chr)
{
	int i;

	i = 0;
	while (str[i] && str[i] != chr)
		i++;
	if (str[i] == chr)
		return (i);
	return (-1);
}

char	*ft_join(char **s1, char *s2)
{
	int		i;
	size_t	size;
	char	*dest;

	i = -1;
	size = (ft_len(*s1) + ft_len(s2));
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (s1[0][++i])
		dest[i] = s1[0][i];
	free(*s1);
	while (*s2)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
