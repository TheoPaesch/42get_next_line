/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaesch <tpaesch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:59:43 by tpaesch           #+#    #+#             */
/*   Updated: 2023/11/27 16:06:48 by tpaesch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*notastring;
	size_t	completesize;
	size_t	i;
	char	*str;

	i = 0;
	completesize = (count * size);
	notastring = malloc(count * size);
	if (!notastring)
		return (NULL);
	str = (char *)notastring;
	if (!str)
		return (NULL);
	while (i < completesize)
		str[i++] = '\0';
	return (notastring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*go;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	go = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!go)
		return (free(go), NULL);
	while (s1[i] != '\0')
	{
		go[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		go[i] = s2[j];
		i++;
		j++;
	}
	return (go);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	size_t	lng;

	lng = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		lng++;
	}
	return (lng);
}
