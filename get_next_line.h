/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:01:04 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/25 14:43:29 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

void	ft_bzero(void *s, int num);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *str);

#endif