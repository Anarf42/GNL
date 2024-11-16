/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:10 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/16 18:06:05 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
inicializar buffer linea 34-35
	//if (buffer == NULL)
		//memset(buffer, 0, BUFFER_SIZE);
*/
/*
gcc -fsanitize=address -g -o a.out *.c
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --verbose ./a.out prueba.txt
lldb ./a.out prueba.txt
*/

static	char	*ft_read(int fd, char *storage)
{
	int		byte_read;
	char	buffer[BUFFER_SIZE];
	char	*tmp;

	byte_read = 1;
	if (storage == NULL)
	{
		storage = malloc(1);
		if (!storage)
			return (NULL);
		storage[0] = '\0';
	}
	while (ft_strchr(storage, '\0') && byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(storage);
			return (NULL);
		}
		if (byte_read == 0)
			return (storage);
		tmp = ft_strjoin(storage, buffer);
		if (!tmp)
		{
			free(storage);
			return (NULL);
		}
		free(storage);
		storage = tmp;
	}
	return (storage);
}

static	char	*extract_line(char *storage)
{
	int		i;
	int		j;
	char	*line;
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
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = storage[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

static	char	*reset_static(char *storage)
{
	int		i;
	int		l;
	int		j;
	char	*new_storage;
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
	l = strlen(storage) - i;
	if (l <= 0 && storage[0] == '\0')
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *)malloc(sizeof(char) * l + 1);
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	while (*tmp++)
		new_storage[j++] = *tmp;
	new_storage[l] = '\0';
	free (storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	storage = reset_static(storage);
	if (!storage)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
