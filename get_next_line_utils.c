/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:08:58 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/03 15:58:24 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;
	size_t	i;
	size_t	j;

	strjoined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!strjoined)
		return (0);
	i = 0;
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		while (s1[++i])
			strjoined[i] = s1[i];
		while (s2[++j])
			strjoined[i] = s2[j];
	}
	strjoined[i] = '\0';
	return (strjoined);
}
