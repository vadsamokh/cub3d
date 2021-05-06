/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:38:24 by vbeech            #+#    #+#             */
/*   Updated: 2020/11/04 14:38:27 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
