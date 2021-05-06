/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:57:55 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/02 18:57:56 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
