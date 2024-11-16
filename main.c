/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:10:56 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/15 16:11:28 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	char	*line;
	int		fd;

	if (argc == 2)
	{
		line = "inicializando..";
		fd = open(argv[1], O_RDONLY);
		while (1)
		{
			line = get_next_line(fd);
			if (!line || !line[0])
				break ;
			printf("%s", line);
			free(line);
		}
	}
	close(fd);
	return (0);
}
