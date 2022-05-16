/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunez-n <enunez-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:08:56 by enunez-n          #+#    #+#             */
/*   Updated: 2022/05/16 16:30:31 by enunez-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffsave[4096];

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	buffsave[fd] = ft_save_buffer(fd, buffsave[fd]);
	if (!buffsave[fd])
		return (NULL);
	line = ft_get_line(buffsave[fd]);
	buffsave[fd] = ft_clean_save(buffsave[fd]);
	return (line);
}

char	*ft_save_buffer(int fd, char *buffsave)
{
	int		bytesread;
	char	*tmp;

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
			free(buffsave);
			return (NULL);
		}
		tmp[bytesread] = '\0';
		if (!buffsave)
			buffsave = ft_newstr();
		buffsave = ft_strjoin(buffsave, tmp);
	}
	free(tmp);
	return (buffsave);
}

char	*ft_get_line(char *buffsave)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffsave[i])
		return (NULL);
	while (buffsave[i] != '\n' && buffsave[i])
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
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
	int		i;
	int		j;

	i = 0;
	while (buffsave[i] && buffsave[i] != '\n')
		i++;
	if (!buffsave[i])
	{
		free(buffsave);
		return (NULL);
	}
	cleaned_buffsave = malloc(ft_strlen(buffsave) - i + 1);
	if (!cleaned_buffsave)
		return (NULL);
	i++;
	j = 0;
	while (buffsave[i])
		cleaned_buffsave[j++] = buffsave[i++];
	cleaned_buffsave[j] = 0;
	free(buffsave);
	return (cleaned_buffsave);
}
