/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:25 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/16 22:28:35 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);

char	*get_next_line(int fd);

#endif