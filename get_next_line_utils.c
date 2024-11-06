/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:40:04 by anruiz-d          #+#    #+#             */
/*   Updated: 2024/11/04 16:28:08 by anruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
 
char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != (char)c))
		i++;
	if (str[i] == (char)c)
		return ((char *)str + i);
	else
		return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*newstr;

	i = 0;
	while (str[i])
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	res = (char *)malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	c;
	int		len;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c] != '\0')
		res[i++] = s2[c++];
	res[i] = '\0';
	return (res);
}


