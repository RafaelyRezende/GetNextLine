/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:56:13 by rluis-ya          #+#    #+#             */
/*   Updated: 2025/06/13 16:11:52 by rluis-ya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_is_nl(char *buff);
char	*get_next_line(int fd);
int		ft_strlen(const char *line);
void	ft_offset(char *buff);
int		ft_init(char **line, int *bytes_read, char *buff);
char	*ft_strjoin(char *s1, char *s2);

#endif
