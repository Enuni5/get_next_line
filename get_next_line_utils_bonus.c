/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:08:58 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/16 16:30:29 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoined;
	char	*temp;
	size_t	len;
	size_t	temp_len;

	strjoined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoined || !s1 || !s2)
		return (NULL);
	temp = strjoined;
	len = ft_strlen(s1);
	temp_len = len;
	while (len--)
		*temp++ = *s1++;
	s1 -= temp_len;
	len = ft_strlen(s2);
	while (len--)
		*temp++ = *s2++;
	*temp = 0;
	free(s1);
	return (strjoined);
}

char	*ft_strchr(char *s, int c)
{
	char	*appear;

	if (s)
	{
		while (*s != '\0')
		{
			if ((char)*s == (char)c)
			{
				appear = (char *)s;
				return (appear);
			}
			s++;
		}
		if (c == 0)
			return (appear = (char *)s);
	}
	return (NULL);
}

char	*ft_newstr(void)
{
	char	*save;

	save = malloc(1);
	if (!save)
		return (NULL);
	*save = 0;
	return (save);
}
