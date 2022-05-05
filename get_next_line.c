/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:08:56 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/05 12:09:50 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffsave;

	buffsave = ft_save_buffer(fd, buffsave);
	if (!buffsave)
		return (NULL);
	line = ft_get_line(buffsave);
	buffsave = ft_clean_save(buffsave);
	return (line);
}

char	*ft_save_buffer(int fd, char *buffsave)
{
	int			bytesr;
	static char	*buffsave;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffsave)
		buffsave = ft_newstr();
	bytesr = 1;
	while (ft_strchr(buffsave, '\n') && bytesr != 0)
	{
		bytesr = read(fd, buffsave, BUFFER_SIZE);
		if (bytesr < 0)
		{
			free(buffsave);
			return (NULL);
		}
		buffsave[bytesr] = '\0';
	}
	return (buffsave);
}

char	*ft_get_line(char *buffsave)
{
	char	*line;
	size_t	i;

}
