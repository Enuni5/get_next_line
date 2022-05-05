/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:08:56 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/05 16:23:17 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffsave;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffsave = ft_save_buffer(fd, buffsave);
	if (!buffsave)
		return (NULL);
	line = ft_get_line(buffsave);
	buffsave = ft_clean_save(buffsave);
	return (line);
}

char	*ft_save_buffer(int fd, char *buffsave)
{
	int		bytesread;
	char	*tmp;

	if (!buffsave)
		buffsave = ft_newstr();
	bytesread = 1;
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	while (!ft_strchr(buffsave, '\n') && bytesread != 0)
	{
		bytesread = read(fd, tmp, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(tmp);
			return (NULL);
		}
		buffsave = ft_strjoin(buffsave, tmp);
		buffsave[bytesread] = '\0';
	}
	return (buffsave);
}

char	*ft_get_line(char *buffsave)
{
	char	*line;
	size_t	i;

	if (!buffsave)
		return (NULL);
	i = 0;
	while (buffsave[i] != '\n' && buffsave[i])
		i++;
	line = malloc(i + 2);
	if (!line)
	{
		free(buffsave);
		return (NULL);
	}
	i = 0;
	while (buffsave[i] != '\n' && buffsave[i])
	{
		line[i] = buffsave[i];
		i++;
	}
	if (buffsave[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*ft_clean_save(char *buffsave)
{
	char	*cleaned_buffsave;
	size_t	i;
	size_t	j;

	if (!buffsave)
		return (NULL);
	i = 0;
	while (buffsave[i] && buffsave[i] != '\n')
		i++;
	cleaned_buffsave = malloc(ft_strlen(buffsave) - i + 1);
	if (!cleaned_buffsave)
	{
		free(buffsave);
		return (NULL);
	}
	j = 0;
	while (buffsave[i] && buffsave[i] != '\n')
		cleaned_buffsave[j++] = buffsave[i++];
	cleaned_buffsave[j] = 0;
	return (cleaned_buffsave);
}
