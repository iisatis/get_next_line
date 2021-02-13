/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:21:31 by pflorent          #+#    #+#             */
/*   Updated: 2021/02/09 16:18:37 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct	s_list
{
	int				fd;
	char			*buff;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
void			ft_reset(t_list **lst);
size_t			ft_len(char *str);
char			*ft_ndup(const char *src, size_t len);
int				ft_chr(const char *str, char chr);
char			*ft_join(t_list **lst, char *s2);

#endif
