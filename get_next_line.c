/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:10 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/14 15:56:07 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_read(int fd, char *storage)
{
	int	byte_read;
	char *buffer;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	if (!storage)
	{
		storage = ft_strdup("");
		while (ft_strchr(storage, '\0') && byte_read)
		{
			byte_read = read(fd, buffer, BUFFER_SIZE);
			if (byte_read == -1)
				return (NULL);
			if (byte_read == 0)
			{
				// TIENES QUE HACES OTRA COSA
				return (storage);
			}
			//TODO: apendizar lo leido al stoage !!!CUIDADO CON LOS LEAKS!!!!
			// cambiar strjoin por strppend
			storage = ft_strjoin(storage, buffer);
		}
	}
	return (storage);
}
static char *extract_line(char *storage)
{
	int i;
	int	j;
	char *line;
	char	*tmp;

	i = 0;
	tmp = storage;
	while (*tmp && *tmp != '\n')
	{
		i++;
		tmp++;
	}
	if (*tmp == '\n')
		i++;
	//*storage -= i;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return NULL;
	j = 0;
	while (i-- > 0)
	{
		line[j] = *storage;
		//line++;
		storage++;
		j++;
	}
	line[j] = '\0';

	return line;
}

static char *reset_static(char *storage)
{
	int i;
	int	l;
	int	j;
	char *new_storage;
	char	*tmp;

	i = 0;
	tmp = storage;
	while (*tmp && *tmp != '\n')
	{
		i++;
		tmp++;
	}
	if (*tmp == '\n')
			i++;
	l = ft_strlen(storage) - i + 1;
	new_storage = (char *)malloc(sizeof(char) * l);
	if (!new_storage)
		return NULL;
	j = 0;
	while (*tmp++)
	{
		new_storage[j++] = *tmp;
		//new_storage++;
		//tmp++;
	}
	new_storage[j] = '\0';
	//revisar si neccesito un puntero auxiliar
	//free(tmp);
	return (new_storage);
}

char *get_next_line(int fd)
{
	char	*line;
	static char *storage;

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
