/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:21:39 by pflorent          #+#    #+#             */
/*   Updated: 2021/02/09 16:18:37 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_reset(t_list **lst)
{
	t_list *prv;
	t_list *nxt;

	nxt = (*lst)->next;
	prv = NULL;
	if ((*lst)->fd != nxt->fd)
	{
		prv = (*lst)->prev;
		prv->next = nxt;
		nxt->prev = prv;
	}
	free((*lst)->buff);
	free(*lst);
	*lst = prv;
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

char	*ft_join(t_list **lst, char *s2)
{
	int		i;
	size_t	size;
	char	*dest;

	i = -1;
	size = (ft_len((*lst)->buff) + ft_len(s2));
	if (!(dest = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while ((*lst)->buff[++i])
		dest[i] = (*lst)->buff[i];
	free((*lst)->buff);
	while (*s2)
	{
		dest[i] = *s2;
		s2++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
