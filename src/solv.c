/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrab <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:02:12 by rhrab             #+#    #+#             */
/*   Updated: 2018/02/19 17:47:17 by rhrab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	store_tetra(t_map *map, t_tetra *tetra, t_offset *offset, char ch)
{
	int		x;
	int		y;

	x = 0;
	while (x < tetra->x)
	{
		y = 0;
		while (y < tetra->y)
		{
			if (tetra->tetramin[y][x] == '#')
				map->map[offset->y + y][offset->x + x] = ch;
			y++;
		}
		x++;
	}
	free(offset);
}

int		put_check(t_map *map, t_offset *offset, t_tetra *tetra)
{
	int		x;
	int		y;

	x = 0;
	while (x < tetra->x)
	{
		y = 0;
		while (y < tetra->y)
		{
			if (tetra->tetramin[y][x] == '#' &&
					map->map[offset->y + y][offset->x + x] != '.')
				return (0);
			y++;
		}
		x++;
	}
	store_tetra(map, tetra, offset, tetra->ch);
	return (1);
}

int		square_solv(t_map *map, t_tetra *tetra, int x, int y)
{
	t_offset	*offset;

	offset = malloc(sizeof(t_offset));
	offset->x = 0;
	offset->y = 0;
	while (tetra != NULL)
	{
		store_tetra(map, tetra, offset, tetra->ch);
		offset = malloc(sizeof(t_offset));
		offset->x = 0;
		offset->y = 0;
		offset->x += x * 2 + 2;
		x++;
		if ((x % (map->size / 2)) == 0)
		{
			y++;
			offset->x = 0;
			x = 0;
		}
		offset->y += y * 2;
		tetra = tetra->next;
	}
	return (1);
}

int		map_solv(t_map *map, t_tetra *tetra)
{
	int		i;
	int		j;

	i = 0;
	if (!tetra)
		return (1);
	while (i < map->size - tetra->y + 1)
	{
		j = 0;
		while (j < map->size - tetra->x + 1)
		{
			if (put_check(map, offset(j, i), tetra))
			{
				if (map_solv(map, tetra->next))
					return (1);
				else
					store_tetra(map, tetra, offset(j, i), '.');
			}
			j++;
		}
		i++;
	}
	return (0);
}
