/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:08:06 by vbeech            #+#    #+#             */
/*   Updated: 2021/03/07 16:08:09 by vbeech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int	parse_map(int fd, char *line, t_params *params)
{
	t_list	*tmp;
	int		a;

	tmp = ft_lstnew(line);
	if (tmp == NULL)
		return (-1);
	while (get_next_line(fd, &line) != 0)
	{
		if (line[0] == '\0')
			return (-2);
		if (new_elem(line, &tmp) == -1)
			return (-1);
	}
	if (new_elem(line, &tmp) == -1)
		return (-1);
	params->map_y = ft_lstsize(tmp);
	if (make_map(tmp, params) == -1)
		return (-1);
	a = check_map(params);
	if (a < 0)
		return (a);
	return (0);
}

int	new_elem(char *line, t_list **tmp)
{
	t_list	*elem;

	elem = ft_lstnew(line);
	if (elem == NULL)
		return (-1);
	ft_lstadd_back(tmp, elem);
	return (0);
}

int	make_map(t_list *tmp, t_params *params)
{
	int		i;
	t_list	*next;

	i = -1;
	next = tmp;
	params->map = (char **)malloc((params->map_y + 1) * sizeof(char *));
	if (params->map == NULL)
	{
		ft_lstclear(&tmp, free);
		return (-1);
	}
	while (next != NULL)
	{
		(params->map)[++i] = ft_strdup(next->content);
		if ((params->map)[i] == NULL)
		{
			memfree_fail(params->map, i);
			ft_lstclear(&tmp, free);
			return (-1);
		}
		next = next->next;
	}
	(params->map)[i + 1] = NULL;
	ft_lstclear(&tmp, free);
	return (0);
}
