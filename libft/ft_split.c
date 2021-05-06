/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:30:58 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/04 16:31:02 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordsct(char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	while (*s != '\0')
	{
		if ((*s != c) && (flag == 0))
		{
			flag = 1;
			count++;
		}
		if (*s == c)
			flag = 0;
		s++;
	}
	return (count);
}

void	memfree_fail(char **mem, size_t i)
{
	size_t	j;

	j = 0;
	while (j <= i)
	{
		free(mem[j]);
		j++;
	}
	free(mem);
}

static char	**meminit(char const *s, char c)
{
	char	**mem;
	size_t	count;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	count = wordsct(s, c);
	len = ft_strlen(s);
	i = 0;
	mem = (char **)ft_calloc(count + 1, sizeof(char *));
	if (mem == NULL)
		return (NULL);
	while (i < count)
	{
		mem[i] = (char *)ft_calloc(len + 1, sizeof(char));
		if (mem[i] == NULL)
		{
			memfree_fail(mem, i);
			return (NULL);
		}
		i++;
	}
	return (mem);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	int		i;
	int		j;

	spl = meminit(s, c);
	if (spl == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			spl[i][j] = *s;
			j++;
		}
		if ((*s == c) && (j != 0))
		{
			i++;
			j = 0;
		}
		s++;
	}
	return (spl);
}
