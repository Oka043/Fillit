/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:57 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/17 16:17:49 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		add_tetra_to_list(t_tetra *tetra)
{
	while (tetra->next != NULL)
	{
		tetra->next = tetra->next->next;
	}
	tetra->next = malloc(sizeof(t_tetra));
	tetra->next->next = NULL;
}

t_offset	*offset(int x, int y)
{
	t_offset	*offset;

	offset = malloc(sizeof(t_offset));
	offset->x = x;
	offset->y = y;
	return (offset);
}

t_map		*map_alloc(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->map = malloc(sizeof(char *) * map->size + 1);
	while (i < map->size)
	{
		j = 0;
		map->map[i] = malloc(sizeof(char) * map->size + 1);
		while (j < map->size)
		{
			map->map[i][j] = '.';
			j++;
		}
		map->map[i][j] = '\0';
		i++;
	}
	return (map);
}
