/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:38:23 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/04 15:38:25 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkset(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static unsigned int	findstart(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while ((checkset(s1[i], set) == 1) && (s1[i] != '\0'))
		i++;
	return (i);
}

static unsigned int	findend(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	while (checkset(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	start;
	unsigned int	end;

	if (s1 == NULL)
		return (NULL);
	start = findstart(s1, set);
	if (s1[start] == '\0')
	{
		trimmed = (char *)malloc(sizeof(char));
		if (trimmed == NULL)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	end = findend(s1, set);
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
