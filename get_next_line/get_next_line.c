/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:57:14 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/16 12:57:16 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_string(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

int	make_s(char **s, char **line, size_t i)
{
	char	*tmp;

	tmp = ft_substr(*s, (unsigned int)i + 1, ft_strlen(*s));
	if (tmp == NULL)
	{
		free(*line);
		return (-1);
	}
	free(*s);
	*s = tmp;
	return (1);
}

int	make_line(char **s, char **line, ssize_t r)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 1;
	while (((*s)[i] != '\n') && ((*s)[i] != '\0'))
		i++;
	if ((r == 0) && (ft_strchr(*s, '\n') == NULL))
		flag = 0;
	*line = ft_substr(*s, 0, i);
	if (*line == NULL)
		return (-1);
	if ((*s)[i] == '\n')
	{
		if (make_s(s, line, i) == -1)
			return (-1);
		if ((*s)[0] == '\0')
			*s = del_string(*s);
	}
	else
		*s = del_string(*s);
	return (flag);
}

int	make_return(char **s, char **line, ssize_t r)
{
	int	ret;

	if (r < 0)
	{
		if (*s != NULL)
			*s = del_string(*s);
		return (-1);
	}
	else if ((r == 0) && (*s == NULL))
	{
		*line = ft_strdup("");
		return (0);
	}
	else
	{
		ret = make_line(s, line, r);
		if ((ret == -1) && (*s != NULL))
			*s = del_string(*s);
		return (ret);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*s[1024];
	char		*tmp;
	char		buf[31];
	ssize_t		r;

	if ((fd < 0) || (line == NULL))
		return (-1);
	r = read(fd, &buf, 30);
	while (r > 0)
	{
		buf[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(s[fd], buf);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n') || (s[fd] == NULL))
			break ;
		r = read(fd, &buf, 30);
	}
	return (make_return(&s[fd], line, r));
}
