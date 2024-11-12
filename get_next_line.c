/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:10 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/12 16:41:46 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_read(int fd, char *storage)
{
	int	byte_read;
	char buffer[BUFFER_SIZE + 1];

	byte_read = 1;
	while (ft_strchr(storage, '\n') && byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		if (byte_read == 0)
		{
			// TIENES QUE HACES OTRA COSA
			return (NULL);
		}
		//TODO: apendizar lo leido al stoage !!!CUIDADO CON LOS LEAKS!!!!
		// cambiar strjoin por strppend
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}
static char *extract_line(char *storage)
{
	int i;
	char *line;

	i = 0;
	while (*storage && *storage != '\n')
	{
		i++;
		storage++;
	}
	if (*storage == '\n')
		i++;
	storage -= i;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return NULL;
	while (*storage && *storage != '\n')
	{
		*line = *storage;
		line++;
		storage++;
	}
	*line = '\0';

	return line;
}

static char *reset_static(char *storage)
{
	int i;
	char *new_storage;

	i = 0;
	while (*storage && *storage != '\n')
	{
		i++;
		storage++;
	}
	if (*storage == '\n')
		i++;
	i = ft_strlen(storage) - i + 1;
	new_storage = (char *)malloc(sizeof(char) * i);
	if (!new_storage)
		return NULL;
	while (*storage)
	{
		*new_storage = *storage;
		new_storage++;
		storage++;
	}
	//revisar si neccesito un puntero auxiliar
	free(storage);
	return (new_storage);
}

char *get_next_line(int fd)
{
	char	*line;
	char static *storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
		return NULL;
	storage = reset_static(storage);
	if (!storage)
		return NULL;
	return (line);
}
