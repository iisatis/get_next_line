/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pflorent <pflorent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:06:32 by pflorent          #+#    #+#             */
/*   Updated: 2021/01/15 17:43:13 by pflorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		get_next_line(int fd, char **line);
void	ft_reset(char **buf);
size_t	ft_len(char *str);
char	*ft_ndup(const char *src, size_t len);
int		ft_chr(const char *str, char chr);
char	*ft_join(char **s1, char *s2);

#endif
