/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:21:24 by pflorent          #+#    #+#             */
/*   Updated: 2021/02/09 16:19:15 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*ft_alloc(size_t size, int fd)
{
	t_list	*lst;
	char	*buff;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	buff = malloc(sizeof(char) * (size + 1));
	if (buff == NULL)
	{
		free(lst);
		return (NULL);
	}
	lst->buff = buff;
	lst->fd = fd;
	lst->prev = lst;
	lst->next = lst;
	buff[0] = '\0';
	return (lst);
}

static t_list	*ft_lstcheck(t_list **lst, int key)
{
	t_list *tmp;
	t_list *new;

	tmp = (*lst)->prev;
	while ((*lst)->fd != key && (*lst)->fd != tmp->fd)
		*lst = (*lst)->next;
	if ((*lst)->fd != key)
	{
		new = ft_alloc(0, key);
		if (new != NULL)
		{
			tmp = (*lst)->next;
			(*lst)->next = new;
			new->next = tmp;
			new->prev = *lst;
			tmp->prev = new;
			*lst = new;
		}
		else
			*lst = NULL;
	}
	return (*lst);
}

static char		*get_line(t_list *lst, int *n)
{
	int		l;
	char	*trim;
	char	*line;

	if ((l = ft_chr(lst->buff, '\n')) == -1)
		*n = 0;
	if (*n == 0)
		l = ft_len(lst->buff);
	if ((line = ft_ndup(lst->buff, l)) == NULL)
		*n = -1;
	l++;
	if (*n == 1)
		if ((trim = ft_ndup(&(lst->buff[l]), ft_len(&(lst->buff[l])))) == NULL)
		{
			free(line);
			*n = -1;
		}
	if (*n == 1)
	{
		free(lst->buff);
		lst->buff = trim;
	}
	return (line);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*lst;
	char			tmp[BUFFER_SIZE + 1];
	long			end_b;
	int				n;

	n = 1;
	if ((fd < 0 || BUFFER_SIZE < 1 || line == NULL || read(fd, tmp, 0) < 0) ||
		(lst == NULL && (lst = ft_alloc(0, fd)) == NULL))
		return (-1);
	if ((lst = ft_lstcheck(&lst, fd)) == NULL)
		return (-1);
	while (ft_chr(lst->buff, '\n') == -1
			&& (end_b = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[end_b] = '\0';
		if ((lst->buff = ft_join(&lst, tmp)) == NULL)
		{
			ft_reset(&lst);
			return (-1);
		}
	}
	*line = get_line(lst, &n);
	if (n != 1)
		ft_reset(&lst);
	return (n);
}
