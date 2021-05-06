/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:23:21 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/20 11:23:23 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join;
	unsigned long	count;

	if (s1 == NULL)
		return (NULL);
	count = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*join = *s1;
		join++;
		s1++;
		count++;
	}
	while (*s2 != '\0')
	{
		*join = *s2;
		join++;
		s2++;
		count++;
	}
	*join = '\0';
	return (join - count);
}

char	*ft_strdup(const char *s1)
{
	unsigned long	len;
	char			*s;

	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*s = *s1;
		s++;
		s1++;
	}
	*s = *s1;
	s = s - len;
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned long	count;

	count = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if ((new == NULL) || (s == NULL))
		return (NULL);
	while ((count < start) && (*s != '\0'))
	{
		s++;
		count++;
	}
	count = 0;
	while ((count < len) && (*s != '\0'))
	{
		*new = *s;
		new++;
		s++;
		count++;
	}
	*new = '\0';
	return (new - count);
}
